--- servers/exchange/storage/e-folder-exchange.c.orig	Mon Oct  3 11:05:51 2005
+++ servers/exchange/storage/e-folder-exchange.c	Thu Nov 10 05:04:23 2005
@@ -744,11 +744,13 @@
 void
 e_folder_exchange_unsubscribe (EFolder *folder)
 {
+	E2kContext *ctx;
+
 	g_return_if_fail (E_IS_FOLDER_EXCHANGE (folder));
 
 	/* FIXME : This is a hack as of now. The free_folder in mail-stub
 	gets called when we are in offline and the context is NULL then. */
-	E2kContext *ctx = E_FOLDER_EXCHANGE_CONTEXT (folder);
+	ctx = E_FOLDER_EXCHANGE_CONTEXT (folder);
 	if (ctx) {
 		e2k_context_unsubscribe (E_FOLDER_EXCHANGE_CONTEXT (folder),
 					 E_FOLDER_EXCHANGE_URI (folder));
