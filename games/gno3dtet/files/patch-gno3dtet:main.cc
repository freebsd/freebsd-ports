--- gno3dtet/main.cc.orig	Thu May  3 12:30:56 2001
+++ gno3dtet/main.cc	Sat Oct  6 02:07:05 2001
@@ -374,6 +374,7 @@
 	textdomain (PACKAGE);
 
 	// init
+	setregid(getegid(), -1);
 	gnome_init_with_popt_table (GNO3DTET_EXENAME, GNO3DTET_VERSION,
 		argc, argv, options, 0, NULL);
 
