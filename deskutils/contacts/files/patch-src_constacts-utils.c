--- src/contacts-utils.c.orig	Sat Sep 30 02:02:40 2006
+++ src/contacts-utils.c	Sat Sep 30 02:03:54 2006
@@ -180,13 +180,13 @@
 
 /* TODO: Would adding a struct for this be gratuititous? RB: NOT AT ALL */
 static const gchar **contacts_field_types[] = {
-	(gchar *[]){ "TEL", "Home", "Msg", "Work", "Pref", "Voice", "Fax",
+	(const gchar *[]){ "TEL", "Home", "Msg", "Work", "Pref", "Voice", "Fax",
 			    "Cell", "Video", "Pager", "BBS", "Modem", "Car",
 			    "ISDN", "PCS", NULL },
-	(gchar *[]){ "EMAIL", "Internet", "X400", "Pref", NULL },
-	(gchar *[]){ "ADR", "Dom", "Intl", "Postal", "Parcel", "Home", "Work",
+	(const gchar *[]){ "EMAIL", "Internet", "X400", "Pref", NULL },
+	(const gchar *[]){ "ADR", "Dom", "Intl", "Postal", "Parcel", "Home", "Work",
 			    "Pref", NULL },
-	(gchar *[]){ NULL }
+	(const gchar *[]){ NULL }
 };
 
 const gchar **
@@ -357,8 +357,8 @@
 			switch (photo->type) {
 			case E_CONTACT_PHOTO_TYPE_INLINED :
 				gdk_pixbuf_loader_write (loader,
-					photo->inlined.data,
-					photo->inlined.length, NULL);
+					photo->data.inlined.data,
+					photo->data.inlined.length, NULL);
 				break;
 			case E_CONTACT_PHOTO_TYPE_URI :
 			default :
@@ -545,9 +545,9 @@
 				int *length;
 #if HAVE_PHOTO_TYPE
 				new_photo.type = E_CONTACT_PHOTO_TYPE_INLINED;
-				data = &new_photo.inlined.data;
-				length = &new_photo.inlined.length;
-				new_photo.inlined.mime_type = NULL;
+				data = &new_photo.data.inlined.data;
+				length = &new_photo.data.inlined.length;
+				new_photo.data.inlined.mime_type = NULL;
 #else
 				data = &new_photo.data;
 				length = &new_photo.length;
