--- storage/innobase/xtrabackup/src/ds_tmpfile.c.orig	2020-04-10 19:45:19 UTC
+++ storage/innobase/xtrabackup/src/ds_tmpfile.c
@@ -55,7 +55,7 @@ datasink_t datasink_tmpfile = {
 	&tmpfile_deinit
 };
 
-MY_TMPDIR mysql_tmpdir_list;
+extern MY_TMPDIR mysql_tmpdir_list;
 
 static ds_ctxt_t *
 tmpfile_init(const char *root)
