--- src/filetypes.h.orig	2010-02-12 10:19:23 UTC
+++ src/filetypes.h
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
