--- program.h.orig	Fri May 30 22:24:52 1997
+++ program.h	Tue Nov 19 12:40:53 2002
@@ -31,6 +31,8 @@
 #ifndef H_PROGRAM
 #define H_PROGRAM
 
+#include <unistd.h>
+#define HAVE_DECL_GETOPT 1
 #include <getopt.h>
 
 class program {
