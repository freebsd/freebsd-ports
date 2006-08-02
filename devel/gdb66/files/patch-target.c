
$FreeBSD$

--- gdb/target.c.orig
+++ gdb/target.c
@@ -1487,13 +1487,14 @@
   struct target_ops **t;
   struct target_ops *runable = NULL;
   int count;
+  extern int kernel_debugging;
 
   count = 0;
 
   for (t = target_structs; t < target_structs + target_struct_size;
        ++t)
     {
-      if ((*t)->to_stratum == core_stratum)
+      if ((*t)->to_stratum == (kernel_debugging ? kcore_stratum : core_stratum))
 	{
 	  runable = *t;
 	  ++count;
