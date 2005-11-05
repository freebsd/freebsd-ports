--- src/castor/comet.cc.orig	Sat Nov  5 12:44:45 2005
+++ src/castor/comet.cc	Sat Nov  5 12:45:28 2005
@@ -15,7 +15,7 @@
 // Copyright 2003 Liam Girdwood  
 
 #include "comet.hh"
-#include <libnova.h>
+#include <libnova/libnova.h>
 #include <libgnomecanvasmm/group.h>
 #include <libgnomecanvasmm/ellipse.h>
 
@@ -60,9 +60,9 @@
 	struct ln_equ_posn posn;
 	
 	if (m_is_parabolic)
-		get_par_body_equ_coords (JD, &m_porbit, &posn);
+		ln_get_par_body_equ_coords (JD, &m_porbit, &posn);
 	else
-		get_ell_body_equ_coords (JD, &m_eorbit, &posn);
+		ln_get_ell_body_equ_coords (JD, &m_eorbit, &posn);
 	
 	ra = posn.ra;
 	dec = posn.dec;
@@ -81,7 +81,7 @@
 	get_equ_posn(JD, ra, dec);
 	equ_posn.ra = ra;
 	equ_posn.dec = dec;
-	get_hrz_from_equ (&equ_posn, observer, JD, posn);
+	ln_get_hrz_from_equ (&equ_posn, observer, JD, posn);
 }
 
 /*! \fn void Comet::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
@@ -90,9 +90,9 @@
 void Comet::get_rst_time (double JD, ln_lnlat_posn* observer, ln_rst_time* time)
 {
 	if (m_is_parabolic)
-		get_par_body_rst(JD, observer, &m_porbit, time);
+		ln_get_par_body_rst(JD, observer, &m_porbit, time);
 	else
-		get_ell_body_rst(JD, observer, &m_eorbit, time);
+		ln_get_ell_body_rst(JD, observer, &m_eorbit, time);
 }
 
 /*! \fn double Comet::get_mag(double JD)
@@ -101,9 +101,9 @@
 double Comet::get_mag(double JD)
 {
 	if (m_is_parabolic)
-		return get_par_comet_mag (JD, &m_porbit, m_g, m_k);
+		return ln_get_par_comet_mag (JD, &m_porbit, m_g, m_k);
 	else
-		return get_ell_comet_mag (JD, &m_eorbit, m_g, m_k);
+		return ln_get_ell_comet_mag (JD, &m_eorbit, m_g, m_k);
 }
 		
 /*! \fn void Comet::get_id(std::string& id)
@@ -135,7 +135,7 @@
 void Comet::render(double x, double y, double mag_max, Gnome::Canvas::Group& group, bool bright, double ppd)
 {
 	// draw object on canvas
-	double size = (mag_max + 1) - get_neptune_magnitude(m_render_JD);
+	double size = (mag_max + 1) - ln_get_neptune_magnitude(m_render_JD);
 	double shadow = 1.1 * size;
 	Gnome::Canvas::Ellipse *ellipse_back, *ellipse;
 	
@@ -161,17 +161,17 @@
 double Comet::get_earth_dist (double JD)
 {
 	if (m_is_parabolic)
-		return get_par_body_earth_dist(JD, &m_porbit);
+		return ln_get_par_body_earth_dist(JD, &m_porbit);
 	else
-		return get_ell_body_earth_dist (JD, &m_eorbit);
+		return ln_get_ell_body_earth_dist (JD, &m_eorbit);
 }
 
 double Comet::get_sun_dist (double JD)
 {
 	if (m_is_parabolic)
-		return get_par_body_solar_dist(JD, &m_porbit);
+		return ln_get_par_body_solar_dist(JD, &m_porbit);
 	else
-		return get_ell_body_solar_dist (JD, &m_eorbit);
+		return ln_get_ell_body_solar_dist (JD, &m_eorbit);
 }
 
 }
