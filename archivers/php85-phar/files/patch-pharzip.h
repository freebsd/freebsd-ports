--- pharzip.h.orig	2025-08-19 05:41:37 UTC
+++ pharzip.h
@@ -17,6 +17,10 @@
   +----------------------------------------------------------------------+
 */
 
+/* Add missing include guard to avoid multiple inclusion */
+#ifndef PHAR_PHARZIP_H
+#define PHAR_PHARZIP_H
+
 typedef struct _phar_zip_file_header {
 	char signature[4];       /* local file header signature     4 bytes  (0x04034b50) */
 	char zipversion[2];      /* version needed to extract       2 bytes */
@@ -238,3 +242,5 @@ typedef struct _phar_zip_dir_end {
 	char comment_len[2];      /* .ZIP file comment length        2 bytes */
 /* .ZIP file comment       (variable size) */
 } phar_zip_dir_end;
+
+#endif /* PHAR_PHARZIP_H */
