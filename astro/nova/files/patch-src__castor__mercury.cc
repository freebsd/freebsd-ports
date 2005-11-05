--- src/castor/mercury.cc.orig	Sat Nov  5 12:45:45 2005
+++ src/castor/mercury.cc	Sat Nov  5 12:49:36 2005
@@ -15,7 +15,7 @@
 // Copyright 2003 Liam Girdwood  
 
 #include "mercury.hh"
-#include <libnova.h>
+#include <libnova/libnova.h>
 
 namespace Castor
 {
@@ -30,7 +30,7 @@
 
 double Mercury::get_disk (double JD)
 {
-	return get_mercury_disk(JD);
+	return ln_get_mercury_disk(JD);
 }
 	
 
@@ -40,7 +40,7 @@
 void Mercury::get_equ_posn (double JD, double& ra, double& dec)
 {
 	struct ln_equ_posn equ;
-	get_mercury_equ_coords (JD, &equ);
+	ln_get_mercury_equ_coords (JD, &equ);
 	ra = equ.ra;
 	dec = equ.dec;
 }
@@ -53,8 +53,8 @@
 {
 	struct ln_equ_posn equ;
 		
-	get_mercury_equ_coords (JD, &equ);
-	get_hrz_from_equ (&equ, observer, JD, posn);
+	ln_get_mercury_equ_coords (JD, &equ);
+	ln_get_hrz_from_equ (&equ, observer, JD, posn);
 }
 
 /*! \fn void Mercury::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
@@ -62,7 +62,7 @@
 */
 void Mercury::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
 {
-	get_mercury_rst(JD, observer, time);
+	ln_get_mercury_rst(JD, observer, time);
 }
 
 /*! \fn double Mercury::get_mag(double JD)
@@ -72,7 +72,7 @@
 {
 	if (JD == 0)
 		JD = m_render_JD;
-	return get_mercury_magnitude (JD);
+	return ln_get_mercury_magnitude (JD);
 }
 		
 /*! \fn void Mercury::get_id(std::string& id)
@@ -104,7 +104,7 @@
 void Mercury::render(double x, double y, double mag_max, Gnome::Canvas::Group& group, bool bright, double ppd)
 {
 	// draw object on canvas
-	double size = (mag_max + 1) - get_mercury_magnitude(m_render_JD);
+	double size = (mag_max + 1) - ln_get_mercury_magnitude(m_render_JD);
 	double sdiam = (get_equ_sdiam(m_render_JD) / 240.0) * ppd;
 	if (size < sdiam)
 		size = sdiam;
@@ -127,37 +127,37 @@
 
 double Mercury::get_earth_dist (double JD)
 {
-	return get_mercury_earth_dist(JD);
+	return ln_get_mercury_earth_dist(JD);
 }
 
 double Mercury::get_sun_dist (double JD)
 {
-	return get_mercury_sun_dist(JD);
+	return ln_get_mercury_solar_dist(JD);
 }
 
 double Mercury::get_equ_sdiam (double JD)
 {
-	return get_mercury_sdiam(JD);
+	return ln_get_mercury_sdiam(JD);
 }
 
 double Mercury::get_pol_sdiam (double JD)
 {
-	return get_mercury_sdiam(JD);
+	return ln_get_mercury_sdiam(JD);
 }
 
 void Mercury::get_helio_coords (double JD, struct ln_helio_posn * position)
 {
-	get_mercury_helio_coords (JD, position);
+	ln_get_mercury_helio_coords (JD, position);
 }
 
 double Mercury::get_phase (double JD)
 {
-	return get_mercury_phase (JD);
+	return ln_get_mercury_phase (JD);
 }
 
 void Mercury::get_rect_helio (double JD, struct ln_rect_posn * position)
 {
-	get_mercury_rect_helio (JD, position);
+	ln_get_mercury_rect_helio (JD, position);
 }
 
 void Mercury::set_render_jd (double JD)
