Upstream patch to fix build with more fresh libgit2 library we have in ports.
Should be removed after updating to 3.18.0

--- libide/git/ide-git-buffer-change-monitor.c.orig	2015-04-08 06:43:25 UTC
+++ libide/git/ide-git-buffer-change-monitor.c
@@ -621,7 +621,7 @@ ide_git_buffer_change_monitor_calculate_
   data = g_bytes_get_data (diff->content, &data_len);
 
   ggit_diff_blob_to_buffer (diff->blob, relative_path, data, data_len, relative_path,
-                            NULL, NULL, NULL, diff_line_cb, (gpointer)diff->state, error);
+                            NULL, NULL, NULL, NULL, diff_line_cb, (gpointer)diff->state, error);
 
   return ((*error) == NULL);
 }
