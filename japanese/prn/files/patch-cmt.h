--- cmt.h.orig	Fri Feb  6 00:13:05 2004
+++ cmt.h	Fri Feb  6 00:13:18 2004
@@ -32,4 +32,4 @@
 /*
  * Error handling function.
  */
-extern void error();
+extern void error(char *, ...);
