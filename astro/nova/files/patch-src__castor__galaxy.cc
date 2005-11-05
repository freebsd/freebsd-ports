--- src/castor/galaxy.cc.orig	Sat Nov  5 12:57:42 2005
+++ src/castor/galaxy.cc	Sat Nov  5 12:58:27 2005
@@ -15,7 +15,7 @@
 // Copyright 2003 Liam Girdwood  
 
 #include "galaxy.hh"
-#include <libnova.h>
+#include <libnova/libnova.h>
 
 namespace Castor
 {
@@ -130,8 +130,8 @@
 {
 	struct ln_equ_posn equ_posn;
 		
-	get_equ_solar_coords(JD, &equ_posn);
-	get_hrz_from_equ (&equ_posn, observer, JD, posn);
+	ln_get_solar_equ_coords(JD, &equ_posn);
+	ln_get_hrz_from_equ (&equ_posn, observer, JD, posn);
 }
 
 /*! \fn void Galaxy::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
