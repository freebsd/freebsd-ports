--- src/init.c.orig	Sun Aug 10 09:37:40 2003
+++ src/init.c	Wed Aug 20 19:23:32 2003
@@ -282,8 +282,8 @@
 	32,		/* groupname_max_length */
 	UUE_NO,	/* hide_uue */
 	KILL_UNREAD,		/* kill_level */
-	MIME_ENCODING_7BIT,		/* mail_mime_encoding */
-	MIME_ENCODING_7BIT,		/* post_mime_encoding */
+	MIME_ENCODING_8BIT,		/* mail_mime_encoding */
+	MIME_ENCODING_8BIT,		/* post_mime_encoding */
 	POST_PROC_NO,			/* post_process */
 	REREAD_ACTIVE_FILE_SECS,	/* reread_active_file_secs */
 	1,		/* scroll_lines */
@@ -330,7 +330,7 @@
 	TRUE,		/* word_highlight */
 	0,		/* wrap_column */
 #ifdef HAVE_COLOR
-	FALSE,		/* use_color */
+	TRUE,		/* use_color */
 #endif /* HAVE_COLOR */
 	TRUE,		/* add_posted_to_filter */
 	TRUE,		/* advertising */
@@ -360,12 +360,12 @@
 #endif /* USE_INVERSE_HACK */
 	TRUE,		/* keep_dead_articles */
 	POSTED_FILE,	/* posted_articles_file */
-	FALSE,		/* mail_8bit_header */
+	TRUE,		/* mail_8bit_header */
 	FALSE,		/* mark_ignore_tags */
 	TRUE,		/* mark_saved_read */
 	TRUE,		/* pgdn_goto_next */
 	TRUE,		/* pos_first_unread */
-	FALSE,		/* post_8bit_header */
+	TRUE,		/* post_8bit_header */
 	TRUE,		/* post_process_view */
 #ifndef DISABLE_PRINTING
 	FALSE,		/* print_header */
