--- client/components/send/send-component.c.orig	Fri Nov 29 16:01:56 2002
+++ client/components/send/send-component.c	Fri Nov 29 16:02:37 2002
@@ -268,7 +268,7 @@
 	list->_maximum = 0;
 	list->_buffer = CORBA_sequence_GNOME_Evolution_Composer_Recipient_allocbuf (0);
 
-	GNOME_Evolution_Composer_setHeaders (composer, list, list, list,
+	GNOME_Evolution_Composer_setHeaders (composer, "", list, list, list,
 					     file_basename, &ev);
 
 	if (BONOBO_EX (&ev)) {
