--- gdb/target.c.orig	Thu Jan 31 17:01:21 2002
+++ gdb/target.c	Fri Jun  7 16:36:06 2002
@@ -1361,7 +1361,11 @@
   for (t = target_structs; t < target_structs + target_struct_size;
        ++t)
     {
+#if defined(__FreeBSD__) && defined(__i386__)
+      if ((*t)->to_stratum == (kernel_debugging ? kcore_stratum : core_stratum))
+#else
       if ((*t)->to_stratum == core_stratum)
+#endif
 	{
 	  runable = *t;
 	  ++count;
