--- src/gzip_et_al.c.orig	2020-05-30 14:10:55 UTC
+++ src/gzip_et_al.c
@@ -109,7 +109,7 @@ gchar *xa_gzip_et_al_get_command (const gchar *program
 	password_str = xa_gzip_et_al_password_str(password, type);
 	workfile = xa_escape_bad_chars(workfile, "\"");
 	archive = xa_quote_shell_command(archive, TRUE);
-	command = g_strconcat("sh -c \"", program, " ", workfile, password_str, type == XARCHIVETYPE_LRZIP ? " -fo " : " -c > ", archive, "\"", NULL);
+	command = g_strconcat("sh -c \"", program, type == XARCHIVETYPE_LRZIP ? " " : " -c ", workfile, password_str, type == XARCHIVETYPE_LRZIP ? " -fo " : " > ", archive, "\"", NULL);
 	g_free(archive);
 	g_free(workfile);
 	g_free(password_str);
@@ -468,7 +468,7 @@ void xa_gzip_et_al_list (XArchive *archive)
 	archive_path = xa_quote_shell_command(archive->path[0], TRUE);
 
 	archive->child_dir = g_strdup(archive->working_dir);
-	command = g_strconcat("sh -c \"", archiver[archive->type].program[0], " -d", password_str, " ", archive_path, lrzip ? " -fo " : " -c > ", decompfile, "\"", NULL);
+	command = g_strconcat("sh -c \"", archiver[archive->type].program[0], lrzip ? " " : " -c ", "-d", password_str, " ", archive_path, lrzip ? " -fo " : " > ", decompfile, "\"", NULL);
 	xa_run_command(archive, command);
 	g_free(command);
 
@@ -702,7 +702,7 @@ gboolean xa_gzip_et_al_extract (XArchive *archive, GSL
 	if (archive->do_overwrite || !g_file_test(out_file, G_FILE_TEST_EXISTS))
 	{
 		password_str = xa_gzip_et_al_password_str(archive->password, archive->type);
-		command = g_strconcat("sh -c \"", archiver[archive->type].program[0], " -d", password_str, " ", archive_path, lrzip ? " -fo " : " -c > ", extraction_dir, "/", files_str, "\"", NULL);
+		command = g_strconcat("sh -c \"", archiver[archive->type].program[0], lrzip ? " " : " -c ", "-d", password_str, " ", archive_path, lrzip ? " -fo " : " > ", extraction_dir, "/", files_str, "\"", NULL);
 		g_free(password_str);
 	}
 	else
@@ -777,7 +777,7 @@ void xa_gzip_et_al_add (XArchive *archive, GSList *fil
 		move = g_strdup("");
 
 	password_str = xa_gzip_et_al_password_str(archive->password, archive->type);
-	command = g_strconcat("sh -c \"", archiver[archive->type].program[0], " -", compress ? "b " : (lrzip ? "L " : ""), compression, password_str, files_str, lrzip ? " -fo " : " -c > ", archive_path, move, "\"", NULL);
+	command = g_strconcat("sh -c \"", archiver[archive->type].program[0], lrzip ? " -" : " -c -", compress ? "b " : (lrzip ? "L " : ""), compression, password_str, files_str, lrzip ? " -fo " : " > ", archive_path, move, "\"", NULL);
 	g_free(password_str);
 
 	g_free(move);
