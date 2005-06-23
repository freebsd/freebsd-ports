--- src/tilp_printl.c.orig	Fri Jun 17 15:14:20 2005
+++ src/tilp_printl.c	Fri Jun 17 15:25:20 2005
@@ -161,6 +161,7 @@
 skip_console:
 #endif
 
+/*
 	if (flog == NULL) {
     		flog = tilp_open_log("a");
 	}
@@ -178,6 +179,7 @@
 
 	// print same stuffs in file
 	vfprintf(flog, format, log_ap);
+*/
 	va_end(log_ap);
 
 	// check for printing domain on next loop
