--- src/vega/virtual_sky.cc.orig	Sat Nov  5 13:00:16 2005
+++ src/vega/virtual_sky.cc	Sat Nov  5 13:02:23 2005
@@ -17,7 +17,7 @@
 #include "virtual_sky.hh"
 #include "astro_object.hh"
 
-#include <libnova.h>
+#include <libnova/libnova.h>
 
 namespace Vega
 {
@@ -430,7 +430,7 @@
 		m_projection->get_position(x, y, ra, dec);
 		equ.ra = ra;
 		equ.dec = dec;
-		get_hrz_from_equ(&equ, &m_observer, m_JD, &hrz);
+		ln_get_hrz_from_equ(&equ, &m_observer, m_JD, &hrz);
 		m_appbar.set_hrz_posn(hrz.alt, hrz.az);
 	} else
 		m_appbar.set_hrz_posn(x,y);
