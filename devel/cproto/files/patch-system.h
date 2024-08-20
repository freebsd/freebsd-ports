--- system.h.orig	2011-01-02 19:23:38 UTC
+++ system.h
@@ -126,7 +126,7 @@
 /* Default C preprocessor on UNIX systems */
 #ifndef MSDOS
 #ifndef CPP
-#define CPP "/lib/cpp"
+#define CPP "/usr/bin/cpp"
 #endif
 #endif
 
