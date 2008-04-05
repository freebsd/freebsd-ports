--- src/wp/ap/unix/ap_UnixApp.cpp.orig	2008-04-01 15:41:39.000000000 -0500
+++ src/wp/ap/unix/ap_UnixApp.cpp	2008-04-01 15:41:46.000000000 -0500
@@ -1240,7 +1240,7 @@
 														 GNOME_PARAM_APP_DATADIR,	PREFIX "/" PACKAGE "-" ABIWORD_SERIES,
 														 GNOME_PARAM_APP_LIBDIR, PREFIX "/" PACKAGE "-" ABIWORD_SERIES,
 														 GNOME_PARAM_POPT_TABLE, AP_Args::options, 
-														 GNOME_PARAM_NONE);
+														 (void *)0);
 #ifdef LOGFILE
 			fprintf(logfile,"gnome_program_init completed \n");
 #endif
