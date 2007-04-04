--- ./test3.c.orig	Sat Jul 20 23:04:08 2002
+++ ./test3.c	Wed Apr  4 12:24:18 2007
@@ -9,7 +9,7 @@
 int main (int argc, char **argv) {
     char *out;
     int newargc, j, f, ret;
-    char **newargv;
+    const char **newargv;
     FILE *fp;
 
     if (argc == 1) {
