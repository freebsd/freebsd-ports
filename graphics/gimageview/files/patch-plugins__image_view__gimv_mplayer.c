Fixes check on unitialized variable
--- plugins/image_view/gimv_mplayer.c.orig	2004-09-29 03:42:14.000000000 -0500
+++ plugins/image_view/gimv_mplayer.c	2014-10-06 23:43:40.000000000 -0400
@@ -1480,13 +1480,13 @@
    gint i, len, size;
    gchar *src, *end;
 
+   src = buf;
+   size = bufsize;
+
    g_return_if_fail (buf && stock_buf);
    g_return_if_fail (size > 0 || size < GIMV_MPLAYER_BUF_SIZE);
    g_return_if_fail (remain_size);
 
-   src = buf;
-   size = bufsize;
-
    while (src && size >= 0) {
       end = NULL;
 
