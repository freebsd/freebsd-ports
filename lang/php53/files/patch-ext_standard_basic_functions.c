--- ext/standard/basic_functions.c.orig	Mon Jan 30 16:58:56 2006
+++ ext/standard/basic_functions.c	Mon Jan 30 16:59:13 2006
@@ -78,6 +78,7 @@
 # include <sys/mman.h>
 #endif
 
+#define HARTMUT_0
 #ifdef HARTMUT_0
 #include <getopt.h>
 #endif
