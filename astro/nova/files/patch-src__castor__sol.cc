--- src/castor/sol.cc.orig	Sat Nov  5 12:06:25 2005
+++ src/castor/sol.cc	Sat Nov  5 12:43:11 2005
@@ -15,7 +15,7 @@
 // Copyright 2003 Liam Girdwood  
 
 #include "sol.hh"
-#include <libnova.h>
+#include <libnova/libnova.h>
 
 namespace Castor
 {
@@ -30,7 +30,7 @@
 
 double Sol::get_sdiam (double JD)
 {
-	return get_solar_sdiam(JD);
+	return ln_get_solar_sdiam(JD);
 }
 	
 /*! \fn void Sol::get_equ_posn (double JD, ln_equ_posn* posn)
@@ -39,7 +39,7 @@
 void Sol::get_equ_posn (double JD, double& ra, double& dec)
 {
 	struct ln_equ_posn posn;
-	get_equ_solar_coords(JD, &posn);
+	ln_get_solar_equ_coords(JD, &posn);
 	ra = posn.ra;
 	dec = posn.dec;
 }
@@ -51,8 +51,8 @@
 {
 	struct ln_equ_posn equ_posn;
 		
-	get_equ_solar_coords(JD, &equ_posn);
-	get_hrz_from_equ (&equ_posn, observer, JD, posn);
+	ln_get_solar_equ_coords(JD, &equ_posn);
+	ln_get_hrz_from_equ (&equ_posn, observer, JD, posn);
 }
 
 /*! \fn void Sol::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
@@ -60,7 +60,7 @@
 */
 void Sol::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
 {
-	get_solar_rst(JD, observer, time);
+	ln_get_solar_rst(JD, observer, time);
 }
 
 /*! \fn double Sol::get_mag()
@@ -100,7 +100,7 @@
 void Sol::render(double x, double y, double mag_max, Gnome::Canvas::Group& group, bool bright, double ppd)
 {
 	// draw object on canvas
-	double size = (mag_max + 1) - get_neptune_magnitude(m_render_JD);
+	double size = (mag_max + 1) - ln_get_neptune_magnitude(m_render_JD);
 	double sdiam = (get_sdiam(m_render_JD) / 240.0) * ppd;
 	if (size < sdiam)
 		size = sdiam;
