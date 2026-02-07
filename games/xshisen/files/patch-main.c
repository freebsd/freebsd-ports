--- main.C.orig	2002-07-07 16:33:55.000000000 +0900
+++ main.C	2011-12-07 11:56:13.000000000 +0900
@@ -210,7 +210,7 @@
     char buffer[100], *p;
     char *(*codeconv)(const char*);
 
-    strcpy(buffer, operation);
+    strncpy(buffer, operation, 99);
     if (strchr(buffer, '-') == NULL) {
         strcat(buffer, "-" KANJICODE);
     }

