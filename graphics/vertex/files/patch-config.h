
$FreeBSD$

--- config.h	2001/06/01 17:19:04	1.1
+++ config.h	2001/06/01 17:19:54
@@ -53,7 +53,7 @@
 /*
  *	File and directory paths:
  */
-#define VMA_DEF_DATA_GLOBAL_DIR		"/usr/share/vertex"
+#define VMA_DEF_DATA_GLOBAL_DIR		(PREFIX "/share/vertex")
 
 /* Local data directory, user's home dir will be prefixed. */
 #define VMA_DEF_DATA_LOCAL_DIR		".vertex"
