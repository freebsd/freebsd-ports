This patch is needed because multimedia/mp4v2 doesn't currently have
MP4LogSetLevel.  It requires mp4v2 >= 2.0.0.

--- mp4.c.orig	2015-07-13 10:00:56 UTC
+++ mp4.c
@@ -155,7 +155,7 @@ static int mp4_open(struct input_plugin_
 		return -IP_ERROR_FUNCTION_NOT_SUPPORTED;
 
 	/* kindly ask mp4v2 to not spam stderr */
-	MP4LogSetLevel(MP4_LOG_NONE);
+	//MP4LogSetLevel(MP4_LOG_NONE);
 
 	/* init private struct */
 	priv = xnew(struct mp4_private, 1);
