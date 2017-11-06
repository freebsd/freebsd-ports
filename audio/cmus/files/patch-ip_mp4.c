This patch is needed because multimedia/mp4v2 doesn't currently have
MP4LogSetLevel.  It requires mp4v2 >= 2.0.0.

--- ip/mp4.c.orig	2016-11-20 12:29:46 UTC
+++ ip/mp4.c
@@ -154,9 +154,6 @@ static int mp4_open(struct input_plugin_
 	if (ip_data->remote)
 		return -IP_ERROR_FUNCTION_NOT_SUPPORTED;
 
-	/* kindly ask mp4v2 to not spam stderr */
-	MP4LogSetLevel(MP4_LOG_NONE);
-
 	/* init private struct */
 	priv = xnew(struct mp4_private, 1);
 	*priv = priv_init;
