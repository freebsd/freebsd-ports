
$FreeBSD$

--- modules/extfs-method.c	2002/02/16 16:49:13	1.1
+++ modules/extfs-method.c	2002/02/16 16:52:11
@@ -52,7 +52,7 @@
 ssize_t getdelim (char **lineptr, size_t *n, int terminator, FILE *stream);
 #endif
 
-#define EXTFS_COMMAND_DIR	PREFIX "/lib/vfs/extfs"
+#define EXTFS_COMMAND_DIR	PREFIX "/lib/vfs2/extfs"
 
 /* Our private handle struct.  */
 struct _ExtfsHandle {
