--- src/main.cc.orig	Wed Mar  9 11:07:47 2005
+++ src/main.cc	Fri Nov 25 23:00:18 2005
@@ -375,6 +375,7 @@
 	textdomain (PACKAGE);
 
 	// init
+	setregid(getegid(), -1);
 //	gnome_init_with_popt_table (GNO3DTET_EXENAME, GNO3DTET_VERSION, argc, argv, options, 0, NULL);// gnome-1
     gnome_program_init (GNO3DTET_EXENAME, GNO3DTET_VERSION,
                 LIBGNOMEUI_MODULE,
