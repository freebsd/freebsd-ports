--- main.c.orig	Tue Jul 27 17:40:25 2004
+++ main.c	Tue Jul 27 17:40:49 2004
@@ -46,7 +46,7 @@
 
     gtk_init(&argc, &argv);
 
-    xml = glade_xml_new(XSTR(UIDIR) "/tunesbrowser.glade", NULL, NULL);
+    xml = glade_xml_new(XSTR(UIDIR) "/tunesbrowser/tunesbrowser.glade", NULL, NULL);
 
     glade_xml_signal_autoconnect(xml);
 
