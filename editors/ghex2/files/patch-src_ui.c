--- src/ui.c.orig	Fri Jul 18 20:25:58 2003
+++ src/ui.c	Fri Jul 18 20:26:34 2003
@@ -875,7 +875,7 @@
 	g_return_if_fail (msg != NULL);
 	va_start(args, msg);
 	real_msg = g_strdup_vprintf(msg, args);
-	va_end(msg);
+	va_end(args);
 	info_dlg = gtk_message_dialog_new (
 			GTK_WINDOW (win),
 			GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
