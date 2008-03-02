--- src/glmid/glscript_swapfile.c.orig	2008-03-02 14:08:24.000000000 -0500
+++ src/glmid/glscript_swapfile.c	2008-03-02 14:09:14.000000000 -0500
@@ -374,6 +374,7 @@ int glscript_init_swapfile()
 	glame_reg_export ("swfd?", 1, 0, 0, gls_is_swfd);
 	glame_reg_export ("swdir?", 1, 0, 0, gls_is_swdir);
 
+#if ! HAVE_GUILE18
 	glame_def_export ("O_CREAT", scm_long2num(O_CREAT));
 	glame_def_export ("O_EXCL", scm_long2num(O_EXCL));
 	glame_def_export ("O_TRUNC", scm_long2num(O_TRUNC));
@@ -381,14 +382,15 @@ int glscript_init_swapfile()
 	glame_def_export ("O_RDONLY", scm_long2num(O_RDONLY));
 	glame_def_export ("O_WRONLY", scm_long2num(O_WRONLY));
 
+	glame_def_export ("SEEK_SET", scm_long2num(SEEK_SET));
+	glame_def_export ("SEEK_CUR", scm_long2num(SEEK_CUR));
+	glame_def_export ("SEEK_END", scm_long2num(SEEK_END));
+#endif
+
 	glame_def_export ("SWSENDFILE_INSERT", 
 			  scm_long2num(SWSENDFILE_INSERT));
 	glame_def_export ("SWSENDFILE_CUT", scm_long2num(SWSENDFILE_CUT));
 	glame_def_export ("SW_NOFILE", swfd2scm(SW_NOFILE));
 
-	glame_def_export ("SEEK_SET", scm_long2num(SEEK_SET));
-	glame_def_export ("SEEK_CUR", scm_long2num(SEEK_CUR));
-	glame_def_export ("SEEK_END", scm_long2num(SEEK_END));
-
 	return 0;
 }
