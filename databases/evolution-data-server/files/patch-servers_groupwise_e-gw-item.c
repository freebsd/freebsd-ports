--- servers/groupwise/e-gw-item.c.orig	Tue Jan 25 20:31:45 2005
+++ servers/groupwise/e-gw-item.c	Tue Jan 25 20:32:28 2005
@@ -2604,8 +2604,8 @@
 
 	/*attachments*/
 	if (priv->attach_list) {
-		soup_soap_message_start_element (msg, "attachments", NULL, NULL) ;
 		GSList *al ;
+		soup_soap_message_start_element (msg, "attachments", NULL, NULL) ;
 		for (al = priv->attach_list ; al != NULL ;  al = al->next) {
 			EGwItemAttachment *attachment = (EGwItemAttachment *)al->data ;
 			add_attachment_to_soap_message (attachment, msg) ;
@@ -2669,8 +2669,8 @@
 
 		/*attachments*/
 		if (priv->attach_list) {
-			soup_soap_message_start_element (msg, "attachments", NULL, NULL) ;
 			GSList *al ;
+			soup_soap_message_start_element (msg, "attachments", NULL, NULL) ;
 			for (al = priv->attach_list ; al != NULL ;  al = al->next) {
 				EGwItemAttachment *attachment = (EGwItemAttachment *)al->data ;
 				add_attachment_to_soap_message (attachment, msg) ;
