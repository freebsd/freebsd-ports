diff --git gdb/i386fbsd-nat.c gdb/i386fbsd-nat.c
index 6c43f2c..a205a26 100644
--- gdb/i386fbsd-nat.c
+++ gdb/i386fbsd-nat.c
@@ -175,7 +175,6 @@ _initialize_i386fbsd_nat (void)
   t->to_read_description = i386fbsd_read_description;
 #endif
 
-  t->to_resume = i386fbsd_resume;
   t->to_pid_to_exec_file = fbsd_pid_to_exec_file;
   t->to_find_memory_regions = fbsd_find_memory_regions;
   add_target (t);
