--- main.c.orig	Tue Apr 13 03:17:50 2004
+++ main.c	Sat Dec 18 00:55:53 2004
@@ -46,7 +46,7 @@
 
     gtk_init(&argc, &argv);
 
-    xml = glade_xml_new(XSTR(UIDIR) "/tunesbrowser.glade", NULL, NULL);
+    xml = glade_xml_new(XSTR(UIDIR) "/gnome/tunesbrowser/tunesbrowser.glade", NULL, NULL);
 
     glade_xml_signal_autoconnect(xml);
