--- program.h.orig	Tue Nov 19 12:53:12 2002
+++ program.h	Tue Nov 19 12:53:20 2002
@@ -31,6 +31,7 @@
 #ifndef H_PROGRAM
 #define H_PROGRAM
 
+#define HAVE_DECL_GETOPT 1
 #include <getopt.h>
 
 class program {
