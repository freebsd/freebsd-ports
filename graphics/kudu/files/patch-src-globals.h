--- src/globals.h.orig	2006-09-12 21:50:10.000000000 +0400
+++ src/globals.h	2010-03-06 20:43:04.000000000 +0300
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
 
