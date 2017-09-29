--- gdb/i386-fbsd-nat.c 2017-09-14 09:28:17 UTC
+++ gdb/i386-fbsd-nat.c
@@ -163,7 +163,6 @@ _initialize_i386fbsd_nat (void)
   t->to_read_description = i386fbsd_read_description;
 #endif
 
-  t->to_resume = i386fbsd_resume;
   fbsd_nat_add_target (t);
 
   /* Support debugging kernel virtual memory images.  */
