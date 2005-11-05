--- src/castor/nebula.cc.orig	Sat Nov  5 12:58:59 2005
+++ src/castor/nebula.cc	Sat Nov  5 12:59:25 2005
@@ -15,7 +15,7 @@
 // Copyright 2003 Liam Girdwood  
 
 #include "nebula.hh"
-#include <libnova.h>
+#include <libnova/libnova.h>
 
 namespace Castor
 {
@@ -30,7 +30,7 @@
 
 double Nebula::get_disk (double JD)
 {
-	return get_solar_sdiam(JD);
+	return ln_get_solar_sdiam(JD);
 }
 	
 /*! \fn void Nebula::get_equ_posn (double JD, ln_equ_posn* posn)
@@ -47,8 +47,8 @@
 {
 	struct ln_equ_posn equ_posn;
 		
-	get_equ_solar_coords(JD, &equ_posn);
-	get_hrz_from_equ (&equ_posn, observer, JD, posn);
+	ln_get_solar_equ_coords(JD, &equ_posn);
+	ln_get_hrz_from_equ (&equ_posn, observer, JD, posn);
 }
 
 /*! \fn void Nebula::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
@@ -56,7 +56,7 @@
 */
 void Nebula::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
 {
-	get_solar_rst(JD, observer, time);
+	ln_get_solar_rst(JD, observer, time);
 }
 
 /*! \fn double Nebula::get_ra()
