--- server.c.orig	Mon Mar 22 21:04:12 2004
+++ server.c	Mon Mar 22 21:32:45 2004
@@ -105,6 +105,7 @@
 {
 	context_p	 context = (context_p) OBEX_GetUserData(handle);
 	struct passwd	*pw = NULL;
+	struct sockaddr *saddr = NULL;
 	gint		 error;
 
 	if (context->user != NULL) {
@@ -169,7 +170,13 @@
 
 	g_message("%s: Starting OBEX server", G_GNUC_FUNCTION);
 
-	if (OBEX_ServerRegister(handle, "OBEX") < 0) {
+	if (( saddr = (struct sockaddr *) g_malloc(sizeof(struct sockaddr))) == NULL) {
+		g_critical("%s(): Could not allocate saddr",
+			G_GNUC_FUNCTION);
+		exit(1);
+	}
+
+	if (OBEX_ServerRegister(handle, saddr, sizeof(struct sockaddr)) < 0) {
 		g_critical("%s(): OBEX_ServerRegister failed", G_GNUC_FUNCTION);
 		return (-1);
 	}
