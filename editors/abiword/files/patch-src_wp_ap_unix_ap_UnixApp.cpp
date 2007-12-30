--- src/wp/ap/unix/ap_UnixApp.cpp.orig	2007-12-30 18:44:50.000000000 -0500
+++ src/wp/ap/unix/ap_UnixApp.cpp	2007-12-30 18:41:23.000000000 -0500
@@ -1405,7 +1405,7 @@ int AP_UnixApp::main(const char * szAppN
 												   GNOME_PARAM_APP_DATADIR,	ABIWORD_DATADIR,
 												   GNOME_PARAM_APP_LIBDIR, ABIWORD_APP_LIBDIR,
 												   GNOME_PARAM_POPT_TABLE, AP_Args::options, 
-												   GNOME_PARAM_NONE);
+												   (void *)0);
 #ifdef LOGFILE
 	fprintf(logfile,"gnome_program_init completed \n");
 #endif
