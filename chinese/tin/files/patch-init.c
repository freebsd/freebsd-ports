--- src/init.c.orig	Sat Sep 23 15:52:42 2000
+++ src/init.c	Sat Sep 23 15:55:26 2000
@@ -270,8 +270,8 @@
 	2,		/* recent_time */
 	32,		/* groupname_max_length */
 	KILL_READ,		/* kill_level */
-	MIME_ENCODING_7BIT,		/* mail_mime_encoding */
-	MIME_ENCODING_7BIT,		/* post_mime_encoding */
+	MIME_ENCODING_8BIT,		/* mail_mime_encoding */
+	MIME_ENCODING_8BIT,		/* post_mime_encoding */
 	POST_PROC_NONE,			/* post_process */
 	REREAD_ACTIVE_FILE_SECS,	/* reread_active_file_secs */
 	SHOW_FROM_NAME,				/* show_author */
@@ -302,7 +302,7 @@
 	0,		/* col_title (initialised later) */
 	2,		/* word_h_display_marks */
 	TRUE,		/* word_highlight */
-	FALSE,		/* use_color */
+	TRUE,		/* use_color */
 #endif /* HAVE_COLOR */
 	TRUE,		/* add_posted_to_filter */
 	TRUE,		/* advertising */
@@ -335,11 +335,11 @@
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
