--- software/tlprender/src/tlprender.cpp.orig	Tue Apr  8 18:34:14 2003
+++ software/tlprender/src/tlprender.cpp	Mon May 26 10:46:44 2003
@@ -8,6 +8,9 @@
 #include <queue>
 
 #include <stdio.h>
+#ifdef __FreeBSD__
+#include <libgen.h>
+#endif
 #include <getopt.h>
   /* from man 3 basename, #include <libgen.h>. However we want to use GNU's basename.
    * see: info libc, libgen.h and string.h for more information. libgen.h is required for dirname,
@@ -54,7 +57,9 @@
 static const int BUFFERSIZE(64 * 1024 * 1024);
 static GLfloat *buffer;
 
+#ifdef HAVE_ON_EXIT
 static void exitManager(int, void *);
+#endif
 static void parseCommandLine(int, char **);
 static void help() __attribute__ ((noreturn));
 
@@ -318,7 +323,9 @@
 /***************************************************************************************************/
 int main (int argc, char **argv)
 {
+#ifdef HAVE_ON_EXIT
   on_exit(exitManager, NULL);
+#endif
 
   parseCommandLine(argc, argv);
   
@@ -401,9 +408,11 @@
 /*
  *
  */
+#ifdef HAVE_ON_EXIT
 void exitManager(int exitStatus, void *arg)
 {
 }
+#endif
 
 /*
  * command line parser and help() functions below this line, nothing else should be added after
