
$FreeBSD$

--- src/rcfile.c.orig
+++ src/rcfile.c
@@ -612,7 +612,7 @@
 {
     char *buf = NULL;
     ssize_t len;
-    size_t n;
+    size_t n = 0;
 
     while ((len = getline(&buf, &n, rcstream)) > 0) {
 	char *ptr, *keyword, *option;
