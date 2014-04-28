--- backend/comics/comics-document.c.orig	2014-03-12 12:54:10.248768412 +0000
+++ backend/comics/comics-document.c	2014-03-12 12:56:38.796852733 +0000
@@ -248,10 +248,13 @@
 	gchar *quoted_file, *quoted_file_aux;
 	gchar *quoted_command;
 	ComicBookDecompressType type;
+
 	
 	type = comics_document->command_usage;
 	comics_document->regex_arg = command_usage_def[type].regex_arg;
 	quoted_command = g_shell_quote (comics_document->selected_command);
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
 	if (comics_document->regex_arg) {
 		quoted_file = comics_regex_quote (comics_document->archive);
 		quoted_file_aux = g_shell_quote (comics_document->archive);
@@ -269,6 +272,7 @@
 	comics_document->extract_command =
 			    g_strdup_printf (command_usage_def[type].extract,
 				             quoted_command);
+#pragma clang diagnostic pop
 	comics_document->offset = command_usage_def[type].offset;
 	if (command_usage_def[type].decompress_tmp) {
 		comics_document->dir = ev_mkdtemp ("evince-comics-XXXXXX", error);
@@ -278,9 +282,12 @@
 		/* unrar-free can't create directories, but ev_mkdtemp already created the dir */
 
 		comics_document->decompress_tmp =
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
 			g_strdup_printf (command_usage_def[type].decompress_tmp, 
 					 quoted_command, quoted_file,
 					 comics_document->dir);
+#pragma clang diagnostic pop
 		g_free (quoted_file);
 		g_free (quoted_command);
 
