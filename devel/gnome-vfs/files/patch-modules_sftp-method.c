--- modules/sftp-method.c.orig	Mon Mar  8 13:52:39 2004
+++ modules/sftp-method.c	Sun Apr  4 13:50:21 2004
@@ -175,6 +175,15 @@
 
 typedef ssize_t (*read_write_fn) (int, void *, size_t);
 
+#ifndef TEMP_FAILURE_RETRY
+#define TEMP_FAILURE_RETRY(expression)				\
+	(__extension__						\
+	 ({ long int __result;					\
+	  	do __result = (long int) (expression);		\
+		while (__result == -1L && errno == EINTR);	\
+		__result; }))
+#endif
+
 static gsize
 atomic_io (read_write_fn f, gint fd, gpointer buffer_in, gsize size) 
 {
@@ -1072,6 +1081,7 @@
 		if (io_status == G_IO_STATUS_NORMAL) {
 			buffer[len] = 0;
 			if (g_str_has_suffix (buffer, "password: ") ||
+			    g_str_has_suffix (buffer, "Password:")  ||
 			    g_str_has_prefix (buffer, "Enter passphrase for key")) {
 				if (invoke_full_auth (uri, done_auth, buffer, &password) && password != NULL) {
 					g_io_channel_write_chars (tty_channel, password, -1, &len, NULL);
