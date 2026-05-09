--- src/GDD.c.orig	2026-05-09 14:15:06 UTC
+++ src/GDD.c
@@ -192,7 +192,7 @@ SEXP gdd_create_new_device(SEXP args)
 	
 	UNPROTECT(2); /* file and type strings */
 	
-	gsetVar(install(".Device"), mkString(devname), R_NilValue);
+        Rf_setVar(install(".Device"), mkString(devname), R_GlobalEnv);
 	dd = GEcreateDevDesc(dev);
 	GEaddDevice(dd);
 	GEinitDisplayList(dd);
