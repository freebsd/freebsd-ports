--- system.h.orig	Fri Jan 23 17:42:09 1998
+++ system.h	Sun Jul 23 12:04:25 2000
@@ -122,15 +122,15 @@
 /* maximum include file nesting */
 #ifndef MAX_INC_DEPTH
-#define MAX_INC_DEPTH 15
+#define MAX_INC_DEPTH 25
 #endif
 
 /* maximum number of include directories */
 #ifndef MAX_INC_DIR
-#define MAX_INC_DIR 15
+#define MAX_INC_DIR 50
 #endif
 
 /* maximum text buffer size */
 #ifndef MAX_TEXT_SIZE
-#define MAX_TEXT_SIZE 256
+#define MAX_TEXT_SIZE 4096
 #endif
