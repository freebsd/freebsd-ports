--- src/xedit.h.orig	Sun Sep 29 02:34:19 2002
+++ src/xedit.h	Sun Sep 29 02:34:41 2002
@@ -225,7 +225,9 @@
 extern void getdirectory();
 
 /* Unix externals */
+#ifndef __FreeBSD__
 extern char *malloc();
+#endif
 
 /* Drag and drop stuff */
 
