--- src/mameio.c.orig	Wed Nov 26 10:38:21 2003
+++ src/mameio.c	Wed Sep  1 18:14:39 2004
@@ -217,7 +217,7 @@
 		
 	/* Generate the list */
 	/* without including neither history nor mameinfo to have less to parse after*/
-	opt=g_strdup_printf("%s -listinfo -%s /dev/null -%s /dev/null 2>/dev/null",
+	opt=g_strdup_printf("%s -listxml -%s /dev/null -%s /dev/null | xml2info 2>/dev/null",
 			current_exec->path,
 			available_options->mameinfo_file_option,
 			available_options->history_file_option);
