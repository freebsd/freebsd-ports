--- gdb/target.c	Thu Jan 31 17:01:21 2002
+++ gdb/target.c	Mon May 27 18:16:52 2002
@@ -1361,7 +1361,7 @@
   for (t = target_structs; t < target_structs + target_struct_size;
        ++t)
     {
-      if ((*t)->to_stratum == core_stratum)
+      if ((*t)->to_stratum == (kernel_debugging ? kcore_stratum : core_stratum))
 	{
 	  runable = *t;
 	  ++count;
