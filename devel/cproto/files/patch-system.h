--- system.h.orig	2008-06-05 16:21:15.000000000 +0400
+++ system.h	2008-06-05 16:21:28.000000000 +0400
@@ -107,7 +107,7 @@
 /* Default C preprocessor on UNIX systems */
 #ifndef MSDOS
 #ifndef CPP
-#define CPP "/lib/cpp"
+#define CPP "/usr/bin/cpp"
 #endif
 #endif
 
