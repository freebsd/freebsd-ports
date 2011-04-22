--- lib/libpm.c.orig	2006-08-19 05:12:28.000000000 +0200
+++ lib/libpm.c	2010-05-21 10:37:10.000000000 +0200
@@ -669,7 +669,7 @@
 pm_openr(const char * const name) {
     FILE* f;
 
-    if (strcmp(name, "-") == 0)
+    if (name == NULL || strcmp(name, "-") == 0)
         f = stdin;
     else {
 #ifndef VMS
@@ -691,7 +691,7 @@
 pm_openw(const char * const name) {
     FILE* f;
 
-    if (strcmp(name, "-") == 0)
+    if (name == NULL || strcmp(name, "-") == 0)
         f = stdout;
     else {
 #ifndef VMS
