--- src/init.c.orig	Sun May 11 14:06:09 2003
+++ src/init.c	Sun May 11 14:07:53 2003
@@ -291,8 +291,8 @@
 	2,		/* recent_time */
 	32,		/* groupname_max_length */
 	KILL_UNREAD,		/* kill_level */
-	MIME_ENCODING_7BIT,		/* mail_mime_encoding */
-	MIME_ENCODING_7BIT,		/* post_mime_encoding */
+	MIME_ENCODING_8BIT,		/* mail_mime_encoding */
+	MIME_ENCODING_8BIT,		/* post_mime_encoding */
 	POST_PROC_NO,			/* post_process */
 	REREAD_ACTIVE_FILE_SECS,	/* reread_active_file_secs */
 	1,		/* scroll_lines */
@@ -339,7 +339,7 @@
 	TRUE,		/* word_highlight */
 	0,		/* wrap_column */
 #ifdef HAVE_COLOR
-	FALSE,		/* use_color */
+	TRUE,		/* use_color */
 #endif /* HAVE_COLOR */
 	TRUE,		/* add_posted_to_filter */
 	TRUE,		/* advertising */
@@ -369,11 +369,11 @@
 #endif /* USE_INVERSE_HACK */
 	TRUE,		/* keep_dead_articles */
 	POSTED_FILE,	/* posted_articles_file */
-	FALSE,		/* mail_8bit_header */
+	TRUE,		/* mail_8bit_header */
 	TRUE,		/* mark_saved_read */
 	TRUE,		/* pgdn_goto_next */
 	TRUE,		/* pos_first_unread */
-	FALSE,		/* post_8bit_header */
+	TRUE,		/* post_8bit_header */
 	TRUE,		/* post_process_view */
 #ifndef DISABLE_PRINTING
 	FALSE,		/* print_header */
