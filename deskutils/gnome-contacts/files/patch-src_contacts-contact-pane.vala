--- src/contacts-contact-pane.vala.orig	2018-01-12 21:20:00 UTC
+++ src/contacts-contact-pane.vala
@@ -451,7 +451,6 @@ public class Contacts.ContactPane : Note
 					 DialogFlags.MODAL,
 					 MessageType.ERROR,
 					 ButtonsType.OK,
-					 "%s",
 					 _("You need to enter some data"));
       dialog.show ();
       dialog.response.connect ( () => {
@@ -463,7 +462,6 @@ public class Contacts.ContactPane : Note
 					 DialogFlags.MODAL,
 					 MessageType.ERROR,
 					 ButtonsType.OK,
-					 "%s",
 					 _("No primary addressbook configured"));
       dialog.show ();
       dialog.response.connect ( () => {
@@ -482,7 +480,6 @@ public class Contacts.ContactPane : Note
 					DialogFlags.MODAL,
 					MessageType.ERROR,
 					ButtonsType.OK,
-					"%s",
 					_("Unable to create new contacts: %s"), e.message);
 	  }
 
@@ -493,7 +490,6 @@ public class Contacts.ContactPane : Note
 					DialogFlags.MODAL,
 					MessageType.ERROR,
 					ButtonsType.OK,
-					"%s",
 					_("Unable to find newly created contact"));
 	  }
 
