--- test3.c.orig	Wed Aug 18 23:57:09 2004
+++ test3.c	Thu Aug 19 00:01:27 2004
@@ -9,7 +9,7 @@
 int main (int argc, char **argv) {
     char *out;
     int newargc, j, f, ret;
-    char **newargv;
+    const char **newargv;
     FILE *fp;
 
     if (argc == 1) {
