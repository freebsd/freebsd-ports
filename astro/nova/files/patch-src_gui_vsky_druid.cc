--- src/gui/vsky_druid.cc.orig	Sat Nov  5 13:04:49 2005
+++ src/gui/vsky_druid.cc	Sat Nov  5 13:07:03 2005
@@ -37,8 +37,8 @@
 	m_is_location_complete = false;	
 	m_is_date_complete = false;		
 	m_is_zone_complete = false;
-	get_ln_date_from_sys(&m_date);
-	m_JD = get_julian_from_sys();
+	ln_get_date_from_sys(&m_date);
+	m_JD = ln_get_julian_from_sys();
 	
 	// create pages
 	create_page_start ();
@@ -738,7 +738,7 @@
 	double latitude;
 	
 	m_lat.degrees = (int)m_lat_deg_spinbutton->get_value();
-	latitude = dms_to_deg(&m_lat);
+	latitude = ln_dms_to_deg(&m_lat);
 	m_vsky->set_latitude(latitude);
 }
 
@@ -747,7 +747,7 @@
 	double latitude;
 	
 	m_lat.minutes = (int)m_lat_min_spinbutton->get_value();
-	latitude = dms_to_deg(&m_lat);
+	latitude = ln_dms_to_deg(&m_lat);
 	m_vsky->set_latitude(latitude);	
 }
 
@@ -756,7 +756,7 @@
 	double latitude;
 	
 	m_lat.seconds = m_lat_sec_spinbutton->get_value();
-	latitude = dms_to_deg(&m_lat);
+	latitude = ln_dms_to_deg(&m_lat);
 	m_vsky->set_latitude(latitude);
 }
 
@@ -765,7 +765,7 @@
 	double longitude;
 	
 	m_long.degrees = (int)m_long_deg_spinbutton->get_value();
-	longitude = dms_to_deg(&m_long);
+	longitude = ln_dms_to_deg(&m_long);
 	m_vsky->set_longitude(longitude);
 }
 
@@ -774,7 +774,7 @@
 	double longitude;
 	
 	m_long.minutes = (int)m_long_min_spinbutton->get_value();
-	longitude = dms_to_deg(&m_long);
+	longitude = ln_dms_to_deg(&m_long);
 	m_vsky->set_longitude(longitude);
 }
 
@@ -783,7 +783,7 @@
 	double longitude;
 	
 	m_long.seconds = m_long_sec_spinbutton->get_value();
-	longitude = dms_to_deg(&m_long);
+	longitude = ln_dms_to_deg(&m_long);
 	m_vsky->set_longitude(longitude);
 }
 
@@ -851,7 +851,7 @@
 	
 	m_date.years = (int)m_year_spinbutton->get_value();
 	refresh_date();
-	JD = get_julian_day(&m_date);
+	JD = ln_get_julian_day(&m_date);
 	m_vsky->set_jd(JD);
 }
 
@@ -861,7 +861,7 @@
 	
 	m_date.months = (int)m_month_spinbutton->get_value();
 	refresh_date();
-	JD = get_julian_day(&m_date);
+	JD = ln_get_julian_day(&m_date);
 	m_vsky->set_jd(JD);
 }
 
@@ -871,7 +871,7 @@
 	
 	m_date.days = (int)m_day_spinbutton->get_value();
 	refresh_date();
-	JD = get_julian_day(&m_date);
+	JD = ln_get_julian_day(&m_date);
 	m_vsky->set_jd(JD);
 }
 
@@ -881,7 +881,7 @@
 	
 	m_date.hours = (int)m_hours_spinbutton->get_value();
 	refresh_date();	
-	JD = get_julian_day(&m_date);
+	JD = ln_get_julian_day(&m_date);
 	m_vsky->set_jd(JD);
 }
 
@@ -891,7 +891,7 @@
 	
 	m_date.minutes = (int)m_minutes_spinbutton->get_value();
 	refresh_date();
-	JD = get_julian_day(&m_date);
+	JD = ln_get_julian_day(&m_date);
 	m_vsky->set_jd(JD);
 }
 
@@ -901,7 +901,7 @@
 	
 	m_date.seconds = m_seconds_spinbutton->get_value();
 	refresh_date();
-	JD = get_julian_day(&m_date);
+	JD = ln_get_julian_day(&m_date);
 	m_vsky->set_jd(JD);
 }
 
@@ -911,7 +911,7 @@
 	
 	m_JD = m_julian_spinbutton->get_value();
 	refresh_date();
-	JD = get_julian_day(&m_date);
+	JD = ln_get_julian_day(&m_date);
 	m_vsky->set_jd(JD);
 }
 
@@ -938,7 +938,7 @@
 	m_use_another_date = false;
 	m_use_julian_date = true;
 	refresh_date();	
-	JD = get_julian_day(&m_date);
+	JD = ln_get_julian_day(&m_date);
 	m_vsky->set_jd(JD);
 }
 
@@ -976,8 +976,8 @@
 void VSkyDruid::refresh_date()
 {	
 	if (m_use_sys_date) {
-		get_ln_date_from_sys(&m_date);
-		m_JD = get_julian_from_sys();
+		ln_get_date_from_sys(&m_date);
+		m_JD = ln_get_julian_from_sys();
 		
 		m_year_spinbutton->set_value(m_date.years);
 		m_month_spinbutton->set_value(m_date.months);
@@ -989,11 +989,11 @@
 		
 	} else if (m_use_another_date) {
 		
-		m_JD = get_julian_day(&m_date);
+		m_JD = ln_get_julian_day(&m_date);
 		m_julian_spinbutton->set_value(m_JD);
 	
 	} else {
-		get_date(m_JD, &m_date);
+		ln_get_date(m_JD, &m_date);
 		
 		m_year_spinbutton->set_value(m_date.years);
 		m_month_spinbutton->set_value(m_date.months);
