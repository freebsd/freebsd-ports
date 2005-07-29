--- mpoly.c.orig	Thu Jun 20 02:27:30 2002
+++ mpoly.c	Sat Jul  9 08:57:27 2005
@@ -636,6 +636,30 @@
 
   proper_printf("Poly/ML RTS version %s\n",poly_runtime_system_version);
 
+#if defined(FREEBSD)
+  /* FreeBSD 5.x links dynamic libraries above the user heap, rather
+     than below the user stack. It determines the base address from
+     the allowed process data size (ulimit -d, limit datasize), the
+     maximum value of which is set by the kernel maxdsiz parameter.
+     If this datasize value is too low, there will be conflicts
+     with the Poly/ML heaps, database or IO Area. Such problems are
+     difficult to diagnose, thus the check here.
+  */
+  struct rlimit rlim;
+  if (getrlimit(RLIMIT_DATA, &rlim) != 0) {
+    proper_fprintf(stderr, "unable to check the datasize resource limit.\n");
+    rlim.rlim_max = 0;
+  }
+  if (rlim.rlim_max < ((rlim_t)IO_TOP - 0x08000000)) {
+    proper_fprintf(stderr,
+	"WARNING: The maximum datasize limit is too low (>= 896M recommended).\n");
+    proper_fprintf(stderr,
+	"WARNING: Large databases may cause problematic behaviour.\n");
+    proper_fprintf(stderr,
+    "WARNING: Please increase resources with limit/ulimit and/or kern.maxdsiz\n");
+  }
+#endif
+
   if (A.filename == 0)
   {
 #ifdef WINDOWS_PC
