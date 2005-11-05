--- src/castor/jupiter.cc.orig	Sat Nov  5 12:52:50 2005
+++ src/castor/jupiter.cc	Sat Nov  5 12:53:17 2005
@@ -15,7 +15,7 @@
 // Copyright 2003 Liam Girdwood  
 
 #include "jupiter.hh"
-#include <libnova.h>
+#include <libnova/libnova.h>
 
 namespace Castor
 {
@@ -30,7 +30,7 @@
 
 double Jupiter::get_disk (double JD)
 {
-	return get_jupiter_disk(JD);
+	return ln_get_jupiter_disk(JD);
 }
 	
 /*! \fn void Jupiter::get_equ_posn (double JD, ln_equ_posn* posn)
@@ -39,7 +39,7 @@
 void Jupiter::get_equ_posn (double JD, double& ra, double& dec)
 {
 	struct ln_equ_posn equ;
-	get_jupiter_equ_coords (JD, &equ);
+	ln_get_jupiter_equ_coords (JD, &equ);
 	ra = equ.ra;
 	dec = equ.dec;
 }
@@ -51,8 +51,8 @@
 {	
 	struct ln_equ_posn equ;
 		
-	get_jupiter_equ_coords (JD, &equ);
-	get_hrz_from_equ (&equ, observer, JD, posn);
+	ln_get_jupiter_equ_coords (JD, &equ);
+	ln_get_hrz_from_equ (&equ, observer, JD, posn);
 }
 
 /*! \fn void Jupiter::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
@@ -60,7 +60,7 @@
 */
 void Jupiter::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
 {
-	get_jupiter_rst(JD, observer, time);
+	ln_get_jupiter_rst(JD, observer, time);
 }
 
 /*! \fn double Jupiter::get_mag(double JD)
@@ -70,7 +70,7 @@
 {
 	if (JD == 0)
 		JD = m_render_JD;
-	return get_jupiter_magnitude (JD);
+	return ln_get_jupiter_magnitude (JD);
 }
 		
 /*! \fn void Jupiter::get_id(std::string& id)
@@ -102,7 +102,7 @@
 void Jupiter::render(double x, double y, double mag_max, Gnome::Canvas::Group& group, bool bright, double ppd)
 {
 	// draw object on canvas
-	double size = (mag_max + 1) - get_jupiter_magnitude(m_render_JD);
+	double size = (mag_max + 1) - ln_get_jupiter_magnitude(m_render_JD);
 	double sdiam = (get_equ_sdiam(m_render_JD) / 240.0) * ppd;
 	if (size < sdiam)
 		size = sdiam;
@@ -126,37 +126,37 @@
 
 double Jupiter::get_earth_dist (double JD)
 {
-	return get_jupiter_earth_dist(JD);
+	return ln_get_jupiter_earth_dist(JD);
 }
 
 double Jupiter::get_sun_dist (double JD)
 {
-	return get_jupiter_sun_dist(JD);
+	return ln_get_jupiter_solar_dist(JD);
 }
 
 double Jupiter::get_equ_sdiam (double JD)
 {
-	return get_jupiter_equ_sdiam(JD);
+	return ln_get_jupiter_equ_sdiam(JD);
 }
 
 double Jupiter::get_pol_sdiam (double JD)
 {
-	return get_jupiter_pol_sdiam(JD);
+	return ln_get_jupiter_pol_sdiam(JD);
 }
 
 void Jupiter::get_helio_coords (double JD, struct ln_helio_posn * position)
 {
-	get_jupiter_helio_coords (JD, position);
+	ln_get_jupiter_helio_coords (JD, position);
 }
 
 double Jupiter::get_phase (double JD)
 {
-	return get_jupiter_phase (JD);
+	return ln_get_jupiter_phase (JD);
 }
 
 void Jupiter::get_rect_helio (double JD, struct ln_rect_posn * position)
 {
-	get_jupiter_rect_helio (JD, position);
+	ln_get_jupiter_rect_helio (JD, position);
 }
 
 void Jupiter::set_render_jd (double JD)
