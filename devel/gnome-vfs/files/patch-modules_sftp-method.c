--- modules/sftp-method.c.orig	Tue May 11 01:53:30 2004
+++ modules/sftp-method.c	Tue May 11 01:54:07 2004
@@ -1081,7 +1081,9 @@
 		if (io_status == G_IO_STATUS_NORMAL) {
 			buffer[len] = 0;
 			if (g_str_has_suffix (buffer, "password: ") ||
+			    g_str_has_suffix (buffer, "password:") ||
 			    g_str_has_suffix (buffer, "Password: ") ||
+			    g_str_has_suffix (buffer, "Password:")  ||
 			    g_str_has_prefix (buffer, "Enter passphrase for key")) {
 				if (invoke_full_auth (uri, done_auth, buffer, &password) && password != NULL) {
 					g_io_channel_write_chars (tty_channel, password, -1, &len, NULL);
