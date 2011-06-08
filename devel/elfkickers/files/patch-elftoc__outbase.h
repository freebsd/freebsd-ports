--- ./elftoc/outbase.h.orig	2011-05-22 20:46:29.000000000 +0200
+++ ./elftoc/outbase.h	2011-06-08 12:16:37.000000000 +0200
@@ -7,6 +7,10 @@
 #ifndef _outbase_h_
 #define _outbase_h_
 
+#ifdef __FreeBSD__
+#define NT_AUXV     6
+#endif
+
 /* Set the current output file. Call this before calling any output
  * functions. (The FILE* argument is given as a void* so as to not
  * include stdio.h here.)
