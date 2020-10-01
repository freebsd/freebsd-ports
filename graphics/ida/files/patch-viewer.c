--- viewer.c.orig	2017-08-30 10:48:03 UTC
+++ viewer.c
@@ -39,7 +39,7 @@
 
 #define PROCESS_LINES    16
 
-int debug;
+extern int debug;
 Cursor ptrs[POINTER_COUNT];
 
 /* ----------------------------------------------------------------------- */
