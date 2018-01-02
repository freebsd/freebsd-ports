--- src/globals.h.orig	2006-09-12 17:50:10 UTC
+++ src/globals.h
@@ -52,6 +52,10 @@
 #include <sys/timeb.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+
+#undef __XSI_VISIBLE
+#define __XSI_VISIBLE 700
+
 #include <dirent.h>
 #include <getopt.h>
 
