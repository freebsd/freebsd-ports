--- tar.c.orig	2012-06-02 08:29:43.000000000 +0200
+++ tar.c	2012-06-02 08:31:37.000000000 +0200
@@ -337,6 +337,15 @@
 			last_was_longlink = 1;
 			/* support the ././@LongLink system for storing long filenames */
 			entry.filename_len = entry.uncompressed_filesize;
+			/* Check for overflow - bug 61065 */
+			if (entry.filename_len == UINT_MAX) {
+				if (error) {
+					spprintf(error, 4096, "phar error: \"%s\" is a corrupted tar file (invalid entry size)", fname);
+				}
+				php_stream_close(fp);
+				phar_destroy_phar_data(myphar TSRMLS_CC);
+				return FAILURE;
+			}
 			entry.filename = pemalloc(entry.filename_len+1, myphar->is_persistent);
 
 			read = php_stream_read(fp, entry.filename, entry.filename_len);
