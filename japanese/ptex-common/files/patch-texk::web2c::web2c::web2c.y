--- texk/web2c/web2c/web2c.y.orig	Tue Dec  9 02:41:52 1997
+++ texk/web2c/web2c/web2c.y	Wed Nov  6 15:29:26 2002
@@ -134,7 +134,8 @@
 
 /* program statement.  Ignore any files.  */
 PROGRAM_HEAD:
 	  program_tok undef_id_tok PROGRAM_FILE_PART ';'
+	  ;
 
 PROGRAM_FILE_PART:
 	  '(' PROGRAM_FILE_LIST ')'
