--- src/gui.c.orig	Mon Nov 15 13:54:11 2004
+++ src/gui.c	Mon Nov 15 13:56:31 2004
@@ -85,7 +85,7 @@
 	glade_gnome_init ();
 
 	// Load and connect glade file
-	g_pXML = glade_xml_new (PACKAGE_SOURCE_DIR"/gRuler.glade", NULL, NULL);
+	g_pXML = glade_xml_new (PACKAGE_DATA_DIR"/glade/gRuler.glade", NULL, NULL);
 	glade_xml_signal_autoconnect (g_pXML);
 
 	// load and configure horizontal ruler
