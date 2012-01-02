--- src/init.c.orig	2011-08-18 12:58:08.564585495 +0800
+++ src/init.c	2011-08-18 12:58:30.264685035 +0800
@@ -354,11 +354,11 @@
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
