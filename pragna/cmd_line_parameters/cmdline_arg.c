#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
/*GPL License*/
MODULE_LICENSE("GPL");
static int param_v;
static char *param_c;
module_param(param_v,int,S_IRUSR|S_IWUSR);
module_param(param_c,charp,S_IRUSR|S_IWUSR);

void display(){
	printk(KERN_INFO "cmd line parameter val=%d \n",param_v);
	printk(KERN_INFO "cmd line string=%s\n",param_c);
	}
static int param_init(void)
	{
	display();
	return 0;
	}

static void param_exit(void)
	{
	printk(KERN_ALERT "Goodbye\n");
	}

module_init(param_init);
module_exit(param_exit);


