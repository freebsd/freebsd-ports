--- lib/libpm.c~	Sun Nov 21 03:55:27 2004
+++ lib/libpm.c	Sat Mar 19 12:39:00 2005
@@ -617,7 +617,7 @@
 pm_openr(const char * const name) {
     FILE* f;
 
-    if (strcmp(name, "-") == 0)
+    if (name == NULL || strcmp(name, "-") == 0)
         f = stdin;
     else {
 #ifndef VMS
@@ -639,7 +639,7 @@
 pm_openw(const char * const name) {
     FILE* f;
 
-    if (strcmp(name, "-") == 0)
+    if (name == NULL || strcmp(name, "-") == 0)
         f = stdout;
     else {
 #ifndef VMS
