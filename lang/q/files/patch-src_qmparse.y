--- src/qmparse.y.orig	2007-11-14 03:07:31.000000000 +0100
+++ src/qmparse.y	2007-11-14 03:09:06.000000000 +0100
@@ -239,7 +239,6 @@
 
 | _PROMPT_ arg_list
 {
-  static savepos();
   char **argv = $2.v;
   int argc = $2.c, i;
   if (argc == 0) {
