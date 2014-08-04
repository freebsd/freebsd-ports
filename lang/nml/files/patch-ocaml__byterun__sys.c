--- ./ocaml/byterun/sys.c.orig	2014-08-02 13:18:24.000000000 -0400
+++ ./ocaml/byterun/sys.c	2014-08-02 13:18:48.000000000 -0400
@@ -71,8 +71,8 @@
 
 #else
 
-extern int sys_nerr;
-extern char * sys_errlist [];
+extern const int sys_nerr;
+extern const char * const sys_errlist [];
 
 char * error_message(void)
 {
