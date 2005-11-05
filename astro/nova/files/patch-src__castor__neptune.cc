--- src/castor/neptune.cc.orig	Sat Nov  5 12:56:34 2005
+++ src/castor/neptune.cc	Sat Nov  5 12:56:51 2005
@@ -15,7 +15,7 @@
 // Copyright 2003 Liam Girdwood  
 
 #include "neptune.hh"
-#include <libnova.h>
+#include <libnova/libnova.h>
 
 namespace Castor
 {
@@ -30,7 +30,7 @@
 
 double Neptune::get_disk (double JD)
 {
-	return get_solar_sdiam(JD);
+	return ln_get_solar_sdiam(JD);
 }
 	
 /*! \fn void Neptune::get_equ_posn (double JD, ln_equ_posn* posn)
@@ -39,7 +39,7 @@
 void Neptune::get_equ_posn (double JD, double& ra, double& dec)
 {
 	struct ln_equ_posn equ;
-	get_neptune_equ_coords (JD, &equ);
+	ln_get_neptune_equ_coords (JD, &equ);
 	ra = equ.ra;
 	dec = equ.dec;
 }
@@ -51,8 +51,8 @@
 {
 	struct ln_equ_posn equ;
 		
-	get_neptune_equ_coords (JD, &equ);
-	get_hrz_from_equ (&equ, observer, JD, posn);
+	ln_get_neptune_equ_coords (JD, &equ);
+	ln_get_hrz_from_equ (&equ, observer, JD, posn);
 }
 
 /*! \fn void Neptune::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
@@ -60,7 +60,7 @@
 */
 void Neptune::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
 {
-	get_neptune_rst(JD, observer, time);
+	ln_get_neptune_rst(JD, observer, time);
 }
 
 /*! \fn double Neptune::get_mag(double JD)
@@ -70,7 +70,7 @@
 {
 	if (JD == 0)
 		JD = m_render_JD;
-	return get_neptune_magnitude (JD);
+	return ln_get_neptune_magnitude (JD);
 }
 		
 /*! \fn void Neptune::get_id(std::string& id)
@@ -102,7 +102,7 @@
 void Neptune::render(double x, double y, double mag_max, Gnome::Canvas::Group& group, bool bright, double ppd)
 {
 	// draw object on canvas
-	double size = (mag_max + 1) - get_neptune_magnitude(m_render_JD);
+	double size = (mag_max + 1) - ln_get_neptune_magnitude(m_render_JD);
 	double sdiam = (get_equ_sdiam(m_render_JD) / 240.0) * ppd;
 	if (size < sdiam)
 		size = sdiam;
@@ -125,37 +125,37 @@
 
 double Neptune::get_earth_dist (double JD)
 {
-	return get_neptune_earth_dist(JD);
+	return ln_get_neptune_earth_dist(JD);
 }
 
 double Neptune::get_sun_dist (double JD)
 {
-	return get_neptune_sun_dist(JD);
+	return ln_get_neptune_solar_dist(JD);
 }
 
 double Neptune::get_equ_sdiam (double JD)
 {
-	return get_neptune_sdiam(JD);
+	return ln_get_neptune_sdiam(JD);
 }
 
 double Neptune::get_pol_sdiam (double JD)
 {
-	return get_neptune_sdiam(JD);
+	return ln_get_neptune_sdiam(JD);
 }
 
 void Neptune::get_helio_coords (double JD, struct ln_helio_posn * position)
 {
-	get_neptune_helio_coords (JD, position);
+	ln_get_neptune_helio_coords (JD, position);
 }
 
 double Neptune::get_phase (double JD)
 {
-	return get_neptune_phase (JD);
+	return ln_get_neptune_phase (JD);
 }
 
 void Neptune::get_rect_helio (double JD, struct ln_rect_posn * position)
 {
-	get_neptune_rect_helio (JD, position);
+	ln_get_neptune_rect_helio (JD, position);
 }
 
 void Neptune::set_render_jd (double JD)
