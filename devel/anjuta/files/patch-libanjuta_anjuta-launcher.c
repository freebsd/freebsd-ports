--- libanjuta/anjuta-launcher.c.orig	2011-06-11 10:39:57.000000000 +0200
+++ libanjuta/anjuta-launcher.c	2011-06-11 10:46:22.000000000 +0200
@@ -761,7 +761,8 @@ anjuta_launcher_scan_output (GIOChannel 
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0) /* There is output */
 			{
 				gchar *utf8_chars = NULL;
@@ -789,6 +790,14 @@ anjuta_launcher_scan_output (GIOChannel 
 				anjuta_launcher_synchronize (launcher);
 				ret = FALSE;
 			}
+			else if (status == G_IO_STATUS_EOF)
+			{
+				launcher->priv->stdout_is_done = TRUE;
+				anjuta_launcher_synchronize (launcher);
+				if (err)
+					g_error_free (err);
+				return FALSE;
+			}
 		/* Read next chars if buffer was too small
 		 * (the maximum length of one character is 6 bytes) */
 		} while (!err && (n > FILE_BUFFER_SIZE - 7));
@@ -818,7 +827,8 @@ anjuta_launcher_scan_error (GIOChannel *
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0) /* There is stderr output */
 			{
 				gchar *utf8_chars;
@@ -844,6 +854,14 @@ anjuta_launcher_scan_error (GIOChannel *
 				anjuta_launcher_synchronize (launcher);
 				ret = FALSE;
 			}
+			else if (status == G_IO_STATUS_EOF)
+			{
+				launcher->priv->stderr_is_done = TRUE;
+				anjuta_launcher_synchronize (launcher);
+				if (err)
+					g_error_free (err);
+				return FALSE;
+			}
 		/* Read next chars if buffer was too small
 		 * (the maximum length of one character is 6 bytes) */
 		} while (!err && (n > FILE_BUFFER_SIZE - 7));
@@ -873,7 +891,8 @@ anjuta_launcher_scan_pty (GIOChannel *ch
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0) /* There is stderr output */
 			{
 				gchar *utf8_chars;
@@ -902,6 +921,11 @@ anjuta_launcher_scan_pty (GIOChannel *ch
 			{
 				ret = FALSE;
 			}
+			else if (status == G_IO_STATUS_EOF)
+			{
+				ret = FALSE;
+				break;
+			}
 		/* Read next chars if buffer was too small
 		 * (the maximum length of one character is 6 bytes) */
 		} while (!err && (n > FILE_BUFFER_SIZE - 7));
