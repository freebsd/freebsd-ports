--- src/castor/deep_object.cc.orig	Sat Nov  5 01:04:20 2005
+++ src/castor/deep_object.cc	Sat Nov  5 01:04:58 2005
@@ -266,8 +266,8 @@
 	struct ln_hms hms;
 	struct ln_dms dms;
 	
-	deg_to_dms (m_dec, &dms);
-	deg_to_hms (m_ra, &hms);
+	ln_deg_to_dms (m_dec, &dms);
+	ln_deg_to_hms (m_ra, &hms);
 	
 	name.push_front(Glib::ustring("Dist(ly)"));
 	sprintf(temp, "%4.2f", m_distance_ly);
