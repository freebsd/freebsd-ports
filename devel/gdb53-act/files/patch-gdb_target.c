--- gdb/target.c	Mon Aug 26 12:18:33 2002
+++ gdb/target.c	Sun Oct 13 10:51:32 2002
@@ -1429,7 +1429,7 @@
   for (t = target_structs; t < target_structs + target_struct_size;
        ++t)
     {
-      if ((*t)->to_stratum == core_stratum)
+      if ((*t)->to_stratum == (kernel_debugging ? kcore_stratum : core_stratum))
 	{
 	  runable = *t;
 	  ++count;
