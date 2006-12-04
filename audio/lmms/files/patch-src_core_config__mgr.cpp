--- src/core/config_mgr.cpp.orig	Mon Dec  4 15:22:34 2006
+++ src/core/config_mgr.cpp	Mon Dec  4 16:00:06 2006
@@ -875,7 +875,7 @@
 #ifdef LADSPA_SUPPORT
 	if( m_ladDir == "" )
 {
-	m_ladDir = "/usr/lib/ladspa/:/usr/local/lib/ladspa/";
+	m_ladDir = "@LOCALBASE@/lib/ladspa/";
 }
 #endif
 
