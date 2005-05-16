--- main.c.orig	Mon May 16 14:27:54 2005
+++ main.c	Mon May 16 14:28:12 2005
@@ -129,7 +129,7 @@
 
     gtk_init(&argc, &argv);
 
-    xml = glade_xml_new(XSTR(UIDIR) "/tunesbrowser.glade", NULL, NULL);
+    xml = glade_xml_new(XSTR(UIDIR) "/tunesbrowser/tunesbrowser.glade", NULL, NULL);
 
     glade_xml_signal_autoconnect(xml);
 
