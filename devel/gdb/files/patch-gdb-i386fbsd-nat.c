diff --git gdb/i386fbsd-nat.c gdb/i386fbsd-nat.c
index 6c43f2c..a205a26 100644
--- gdb/i386fbsd-nat.c
+++ gdb/i386fbsd-nat.c
@@ -175,7 +175,6 @@ _initialize_i386fbsd_nat (void)
   t->to_read_description = i386fbsd_read_description;
 #endif
 
-  t->to_resume = i386fbsd_resume;
   fbsd_nat_add_target (t);
   /* Support debugging kernel virtual memory images.  */
