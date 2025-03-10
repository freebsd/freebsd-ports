--- mkcramfs.c.orig	Wed Nov 29 12:47:30 2006
+++ mkcramfs.c	Wed Nov 29 12:49:25 2006
@@ -36,6 +36,9 @@
 #include <linux/cramfs_fs.h>
 #include <zlib.h>
 
+#define	MAP_ANONYMOUS	MAP_ANON
+typedef	long long	loff_t;
+
 /* Exit codes used by mkfs-type programs */
 #define MKFS_OK          0	/* No errors */
 #define MKFS_ERROR       8	/* Operational error */
