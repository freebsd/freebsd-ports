--- libanjuta/anjuta-launcher.c.orig	2008-02-15 18:32:29.000000000 -0500
+++ libanjuta/anjuta-launcher.c	2008-02-25 22:45:03.000000000 -0500
@@ -37,7 +37,7 @@
 #include <signal.h>
 
 #if !defined(__sun) && !defined(__NetBSD__)
-#  ifndef FREEBSD
+#  if !defined(__FreeBSD__)
 #    include <pty.h>
 #  else
 #    include <libutil.h>
@@ -749,7 +749,8 @@ anjuta_launcher_scan_output (GIOChannel 
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0) /* There is output */
 			{
 				gchar *utf8_chars;
@@ -776,6 +777,13 @@ anjuta_launcher_scan_output (GIOChannel 
 				anjuta_launcher_synchronize (launcher);
 				ret = FALSE;
 			}
+			else if (status == G_IO_STATUS_EOF)
+			{
+				launcher->priv->stdout_is_done = TRUE;
+				anjuta_launcher_synchronize (launcher);
+				ret = FALSE;
+			}
+
 		/* Read next chars if buffer was too small
 		 * (the maximum length of one character is 6 bytes) */
 		} while (!err && (n > FILE_BUFFER_SIZE - 7));
@@ -805,7 +813,8 @@ anjuta_launcher_scan_error (GIOChannel *
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0) /* There is stderr output */
 			{
 				gchar *utf8_chars;
@@ -833,6 +842,13 @@ anjuta_launcher_scan_error (GIOChannel *
 				anjuta_launcher_synchronize (launcher);
 				ret = FALSE;
 			}
+			else if (status == G_IO_STATUS_EOF)
+			{
+				launcher->priv->stderr_is_done = TRUE;
+				anjuta_launcher_synchronize (launcher);
+				ret = FALSE;
+			}
+
 		/* Read next chars if buffer was too small
 		 * (the maximum length of one character is 6 bytes) */
 		} while (!err && (n > FILE_BUFFER_SIZE - 7));
@@ -862,7 +878,8 @@ anjuta_launcher_scan_pty (GIOChannel *ch
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0) /* There is stderr output */
 			{
 				gchar *utf8_chars;
@@ -893,6 +910,10 @@ anjuta_launcher_scan_pty (GIOChannel *ch
 				g_warning ("pty: %s", err->message);
 				ret = FALSE;
 			}
+			else if (status == G_IO_STATUS_EOF)
+			{
+				ret = FALSE;
+			}
 		/* Read next chars if buffer was too small
 		 * (the maximum length of one character is 6 bytes) */
 		} while (!err && (n > FILE_BUFFER_SIZE - 7));
