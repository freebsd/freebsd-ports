--- liboil/liboilcpu.c.orig	Sun Nov 28 13:15:12 2004
+++ liboil/liboilcpu.c	Sun Nov 28 13:15:41 2004
@@ -64,6 +64,7 @@
   char **f;
 
   cpuinfo = get_cpuinfo();
+  if (cpuinfo == NULL) return;
 
   cpuinfo_flags = get_cpuinfo_flags_string(cpuinfo);
   if (cpuinfo_flags == NULL) return;
