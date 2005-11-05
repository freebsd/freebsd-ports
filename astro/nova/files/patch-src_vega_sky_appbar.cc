--- src/vega/sky_appbar.cc.orig	Sat Nov  5 13:03:00 2005
+++ src/vega/sky_appbar.cc	Sat Nov  5 13:03:35 2005
@@ -16,7 +16,7 @@
 
 #include "sky_appbar.hh"
 
-#include <libnova.h>
+#include <libnova/libnova.h>
 
 namespace Vega
 {
@@ -124,8 +124,8 @@
 	struct ln_dms hdec;
 	char text[32];
 	
-	deg_to_dms (dec, &hdec);
-	deg_to_hms (ra, &hra);
+	ln_deg_to_dms (dec, &hdec);
+	ln_deg_to_hms (ra, &hra);
 	
 	sprintf(text, "%2.2d", hra.hours);
 	m_equ_rah.set_text(text);
@@ -151,8 +151,8 @@
 	struct ln_dms halt, haz;
 	char text[32];
 	
-	deg_to_dms (alt, &halt);
-	deg_to_dms (az, &haz);
+	ln_deg_to_dms (alt, &halt);
+	ln_deg_to_dms (az, &haz);
 	
 	sprintf(text, "%2.2d", halt.degrees);
 	m_hrz_ald.set_text(text);
