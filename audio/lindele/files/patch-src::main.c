--- src/main.c.orig	Tue Jan 18 02:24:29 2005
+++ src/main.c	Tue Jan 18 02:24:53 2005
@@ -21,6 +21,8 @@
 int
 main (int argc, char *argv[])
 {
+    Lindele *lindele;
+
     gst_init(&argc, &argv);
     glade_init();
     gnome_program_init ("lindele", VERSION,
@@ -28,7 +30,7 @@
 		    argc, argv,
 		    GNOME_PARAM_APP_DATADIR, DATADIR, NULL);
     
-    Lindele *lindele = lindele_new();
+    lindele = lindele_new();
     
     gtk_main();
     
