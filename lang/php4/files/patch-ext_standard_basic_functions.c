--- ext/standard/basic_functions.c.orig	Mon Jan 30 15:58:01 2006
+++ ext/standard/basic_functions.c	Mon Jan 30 15:58:36 2006
@@ -66,6 +66,7 @@
 # include <sys/mman.h>
 #endif
 
+#define HARTMUT_0
 #ifdef HARTMUT_0
 #include <getopt.h>
 #endif
