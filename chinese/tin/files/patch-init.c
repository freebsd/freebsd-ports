--- src/init.c.orig	Wed Jan  8 23:43:57 2003
+++ src/init.c	Wed Jan  8 23:45:36 2003
@@ -289,8 +289,8 @@
 	2,		/* recent_time */
 	32,		/* groupname_max_length */
 	KILL_READ,		/* kill_level */
-	MIME_ENCODING_7BIT,		/* mail_mime_encoding */
-	MIME_ENCODING_7BIT,		/* post_mime_encoding */
+	MIME_ENCODING_8BIT,		/* mail_mime_encoding */
+	MIME_ENCODING_8BIT,		/* post_mime_encoding */
 	POST_PROC_NONE,			/* post_process */
 	REREAD_ACTIVE_FILE_SECS,	/* reread_active_file_secs */
 	1,		/* scroll_lines */
@@ -333,7 +333,7 @@
 	TRUE,		/* word_highlight */
 	0,		/* wrap_column */
 #ifdef HAVE_COLOR
-	FALSE,		/* use_color */
+	TRUE,		/* use_color */
 #endif /* HAVE_COLOR */
 	TRUE,		/* add_posted_to_filter */
 	TRUE,		/* advertising */
@@ -364,11 +364,11 @@
 	TRUE,		/* keep_dead_articles */
 	TRUE,		/* keep_posted_articles */
 	POSTED_FILE,	/* keep_posted_articles_file */
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
