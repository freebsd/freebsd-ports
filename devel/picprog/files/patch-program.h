--- program.h.orig	Thu Jan  1 20:35:09 2004
+++ program.h	Fri Jul  8 21:44:23 2005
@@ -30,6 +30,7 @@
 #ifndef H_PROGRAM
 #define H_PROGRAM
 
+#define HAVE_DECL_GETOPT 1
 #include <getopt.h>
 
 class program {
