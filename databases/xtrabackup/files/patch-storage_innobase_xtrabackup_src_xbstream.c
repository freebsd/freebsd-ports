--- storage/innobase/xtrabackup/src/xbstream.c.orig	2020-04-10 19:45:19 UTC
+++ storage/innobase/xtrabackup/src/xbstream.c
@@ -55,7 +55,6 @@ datasink_t datasink_xbstream;
 datasink_t datasink_compress;
 datasink_t datasink_tmpfile;
 datasink_t datasink_encrypt;
-datasink_t datasink_buffer;
 
 static run_mode_t	opt_mode;
 static char *		opt_directory = NULL;
