--- source/window.c.orig	2014-11-23 15:23:37 UTC
+++ source/window.c
@@ -4509,7 +4509,8 @@ window_get_query_nick(Window *window)
 void
 add_to_window_log(Window *window, u_char *str)
 {
-	add_to_log(window->log_fp, str);
+	if (window->log)
+		add_to_log(window->log_fp, str);
 }
 
 LastlogInfo *
