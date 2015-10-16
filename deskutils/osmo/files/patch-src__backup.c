--- src/backup.c.orig	2015-08-08 07:10:12 UTC
+++ src/backup.c
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
