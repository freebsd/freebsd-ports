--- libanjuta/anjuta-launcher.c.orig	Mon Jun 11 13:22:08 2007
+++ libanjuta/anjuta-launcher.c	Sun Jul  8 03:39:07 2007
@@ -37,7 +37,7 @@
 #include <signal.h>
 
 #if !defined(__sun) && !defined(__NetBSD__)
-#  ifndef FREEBSD
+#  if !defined(__FreeBSD__)
 #    include <pty.h>
 #  else
 #    include <libutil.h>
@@ -713,7 +713,8 @@ anjuta_launcher_scan_output (GIOChannel 
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0 && !err) /* There is output */
 			{
 				gchar *utf8_chars;
@@ -733,6 +734,13 @@ anjuta_launcher_scan_output (GIOChannel 
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
@@ -762,7 +770,8 @@ anjuta_launcher_scan_error (GIOChannel *
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0 && !err) /* There is stderr output */
 			{
 				gchar *utf8_chars;
@@ -782,6 +791,13 @@ anjuta_launcher_scan_error (GIOChannel *
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
@@ -811,7 +827,8 @@ anjuta_launcher_scan_pty (GIOChannel *ch
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0 && !err) /* There is stderr output */
 			{
 				gchar *utf8_chars;
@@ -833,6 +850,10 @@ anjuta_launcher_scan_pty (GIOChannel *ch
 			else if (err && errno != EAGAIN && errno != EINTR)
 			{
 				g_warning (_("launcher.c: Error while reading child pty\n"));
+				ret = FALSE;
+			}
+			else if (status == G_IO_STATUS_EOF)
+			{
 				ret = FALSE;
 			}
 		/* Read next chars if buffer was too small
