--- lib/direct/log.c.orig	2007-03-03 22:29:45.000000000 +0200
+++ lib/direct/log.c	2008-03-12 12:49:22.000000000 +0200
@@ -49,6 +49,14 @@
 #include <direct/util.h>
 
 
+#ifndef EAI_ADDRFAMILY
+#define EAI_ADDRFAMILY   1
+#endif
+#ifndef EAI_NODATA
+#define EAI_NODATA       7
+#endif
+
+
 struct __D_DirectLog {
      int            magic;
 
