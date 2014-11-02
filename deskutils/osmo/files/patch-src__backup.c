--- src/backup.c.orig	2014-10-19 00:26:19.000000000 +0900
+++ src/backup.c	2014-10-19 00:32:50.000000000 +0900
@@ -41,6 +41,14 @@
 #include <archive.h>
 #include <archive_entry.h>
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#if __FreeBSD_version <= 1000008 /* r232154: bump for libarchive update */
+#define archive_read_support_filter_all(x) \
+	archive_read_support_compression_all(x)
+#endif
+#endif
+
 /*------------------------------------------------------------------------------*/
 
 int
