--- src/castor/asteroid.cc.orig	Sat Nov  5 12:43:37 2005
+++ src/castor/asteroid.cc	Sat Nov  5 12:44:30 2005
@@ -15,7 +15,7 @@
 // Copyright 2003 Liam Girdwood  
 
 #include "asteroid.hh"
-#include <libnova.h>
+#include <libnova/libnova.h>
 #include <libgnomecanvasmm/group.h>
 #include <libgnomecanvasmm/ellipse.h>
 
@@ -47,7 +47,7 @@
 void Asteroid::get_equ_posn (double JD, double& ra, double& dec)
 {
 	struct ln_equ_posn posn;
-	get_ell_body_equ_coords (JD, &m_orbit, &posn);
+	ln_get_ell_body_equ_coords (JD, &m_orbit, &posn);
 	ra = posn.ra;
 	dec = posn.dec;
 }
@@ -63,7 +63,7 @@
 	get_equ_posn(JD, ra, dec);
 	equ_posn.ra = ra;
 	equ_posn.dec = dec;
-	get_hrz_from_equ (&equ_posn, observer, JD, posn);
+	ln_get_hrz_from_equ (&equ_posn, observer, JD, posn);
 }
 
 /*! \fn void Asteroid::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
@@ -71,7 +71,7 @@
 */
 void Asteroid::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
 {
-	get_ell_body_rst(JD, observer, &m_orbit, time);
+	ln_get_ell_body_rst(JD, observer, &m_orbit, time);
 }
 
 /*! \fn double Asteroid::get_mag(double JD)
@@ -79,7 +79,7 @@
 */
 double Asteroid::get_mag(double JD)
 {
-	get_asteroid_mag (JD, &m_orbit, m_H, m_G);
+	ln_get_asteroid_mag (JD, &m_orbit, m_H, m_G);
 }
 		
 /*! \fn void Asteroid::get_id(std::string& id)
@@ -111,7 +111,7 @@
 void Asteroid::render(double x, double y, double mag_max, Gnome::Canvas::Group& group, bool bright, double ppd)
 {
 	// draw object on canvas
-	double size = (mag_max + 1) - get_neptune_magnitude(m_render_JD);
+	double size = (mag_max + 1) - ln_get_neptune_magnitude(m_render_JD);
 	double sdiam = (get_sdiam_arc(m_render_JD) / 240.0) * ppd;
 	if (size < sdiam)
 		size = sdiam;
@@ -134,22 +134,22 @@
 
 double Asteroid::get_earth_dist (double JD)
 {
-	return get_ell_body_earth_dist (JD, &m_orbit);
+	return ln_get_ell_body_earth_dist (JD, &m_orbit);
 }
 
 double Asteroid::get_sun_dist (double JD)
 {
-	return get_ell_body_solar_dist (JD, &m_orbit);
+	return ln_get_ell_body_solar_dist (JD, &m_orbit);
 }
 
 double Asteroid::get_sdiam_km ()
 {
-	return get_asteroid_sdiam_km(m_H, m_A);
+	return ln_get_asteroid_sdiam_km(m_H, m_A);
 }
 
 double Asteroid::get_sdiam_arc (double JD)
 {
-	return get_asteroid_sdiam_arc(JD, &m_orbit, m_H, m_A);
+	return ln_get_asteroid_sdiam_arc(JD, &m_orbit, m_H, m_A);
 }
 
 void Asteroid::set_render_jd (double JD)
