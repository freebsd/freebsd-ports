--- src/init.c.orig	2014-07-16 00:47:37.352661040 +0800
+++ src/init.c	2014-07-16 00:48:08.424652944 +0800
@@ -361,11 +361,11 @@
 #endif /* USE_INVERSE_HACK */
 	TRUE,		/* keep_dead_articles */
 	POSTED_FILE,	/* posted_articles_file */
-	FALSE,		/* mail_8bit_header */
+	TRUE,		/* mail_8bit_header */
 	FALSE,		/* mark_ignore_tags */
 	TRUE,		/* mark_saved_read */
 	TRUE,		/* pos_first_unread */
-	FALSE,		/* post_8bit_header */
+	TRUE,		/* post_8bit_header */
 	TRUE,		/* post_process_view */
 #ifndef DISABLE_PRINTING
 	FALSE,		/* print_header */
