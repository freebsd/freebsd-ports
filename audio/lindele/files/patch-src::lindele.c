--- src/lindele.c.orig	Tue Jan 18 02:30:18 2005
+++ src/lindele.c	Tue Jan 18 02:30:28 2005
@@ -82,6 +82,7 @@
     const gchar *documenters[] = {NULL};
     const gchar *translator_credits = NULL;
     GdkPixbuf *logo_pixbuf = gdk_pixbuf_new_from_file(LINDELE_PNG,NULL);
+    gchar *gladepath;
     
     object->mmkeys = mmkeys_new();
     object->player = init_player();
@@ -90,7 +91,7 @@
     object->random = FALSE;
     object->repeat = FALSE;
 
-    gchar* gladepath = g_strconcat(DATADIR,"/lindele/lindele.glade",NULL);
+    gladepath = g_strconcat(DATADIR,"/lindele/lindele.glade",NULL);
 	//gchar* gladepath = g_strconcat("/home/link/Hacking/lindele/lindele-head/data/lindele.glade",NULL);
 	
 	object->xml = glade_xml_new (gladepath, NULL, NULL);
