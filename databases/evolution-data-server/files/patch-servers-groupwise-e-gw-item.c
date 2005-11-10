--- servers/groupwise/e-gw-item.c.orig	Mon Oct  3 14:46:42 2005
+++ servers/groupwise/e-gw-item.c	Thu Nov 10 04:56:48 2005
@@ -3019,8 +3019,8 @@
 
 	/*attachments*/
 	if (priv->attach_list) {
-		soup_soap_message_start_element (msg, "attachments", NULL, NULL) ;
 		GSList *al ;
+		soup_soap_message_start_element (msg, "attachments", NULL, NULL) ;
 		for (al = priv->attach_list ; al != NULL ;  al = al->next) {
 			EGwItemAttachment *attachment = (EGwItemAttachment *)al->data ;
 			add_attachment_to_soap_message (attachment, msg) ;
