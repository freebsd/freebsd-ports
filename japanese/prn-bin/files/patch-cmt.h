--- cmt.h.orig	1993-11-29 10:00:33 UTC
+++ cmt.h
@@ -32,4 +32,4 @@ typedef int bool;
 /*
  * Error handling function.
  */
-extern void error();
+extern void error(char *, ...);
