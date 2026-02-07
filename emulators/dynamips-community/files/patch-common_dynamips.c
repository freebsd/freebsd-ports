--- common/dynamips.c.orig	2017-07-24 11:37:51 UTC
+++ common/dynamips.c
@@ -190,7 +190,7 @@ static void show_usage(vm_instance_t *vm,int argc,char
           "2691, 3725, 3745, 2600 or 1700) "
           "(default: 7200)\n\n"
           "  -l <log_file>      : Set logging file (default is %s)\n"
-          "  -j                 : Disable the JIT compiler, very slow\n"
+/*          "  -j                 : Disable the JIT compiler, very slow\n" */
           "  --idle-pc <pc>     : Set the idle PC (default: disabled)\n"
           "  --timer-itv <val>  : Timer IRQ interval check (default: %u)\n"
           "\n"
@@ -394,7 +394,7 @@ static vm_instance_t *cli_create_instance(char *name,c
 static int parse_std_cmd_line(int argc,char *argv[])
 {
    char *options_list =
-      "r:o:n:c:m:l:C:i:jt:p:s:k:T:U:A:B:a:f:E:b:S:R:M:eXP:N:G:g:L:I:";
+      "r:o:n:c:m:l:C:i:t:p:s:k:T:U:A:B:a:f:E:b:S:R:M:eXP:N:G:g:L:I:";
    vm_platform_t *platform;
    vm_instance_t *vm = NULL;
    int instance_id;
@@ -563,11 +563,6 @@ static int parse_std_cmd_line(int argc,char *argv[])
             }
 
             printf("Using a clock divisor of %d.\n",vm->clock_divisor);
-            break;
-
-         /* Disable JIT */
-         case 'j':
-            vm->jit_use = FALSE;
             break;
 
          /* VM debug level */
