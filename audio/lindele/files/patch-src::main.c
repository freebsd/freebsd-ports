--- src/main.c.orig	Mon Jul 26 22:14:22 2004
+++ src/main.c	Mon Jul 26 22:14:39 2004
@@ -21,6 +21,8 @@
 int
 main (int argc, char *argv[])
 {
+    Lindele lindele;
+
     gst_init(&argc, &argv);
     glade_init();
     gnome_program_init ("lindele", VERSION,
@@ -28,7 +30,6 @@
 		    argc, argv,
 		    GNOME_PARAM_APP_DATADIR, DATADIR, NULL);
     
-    Lindele lindele;
     init_lindele(&lindele);
     
     gtk_main();
