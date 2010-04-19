--- src/filetypes.h.orig	2010-04-19 22:01:16.000000000 +0200
+++ src/filetypes.h	2010-04-19 22:04:16.000000000 +0200
@@ -81,5 +81,9 @@
 #ifndef S_ISLNK
 #define lstat stat
 #endif
+#ifndef lstat
 int lstat ();
+#endif
+#ifndef stat
 int stat ();
+#endif
