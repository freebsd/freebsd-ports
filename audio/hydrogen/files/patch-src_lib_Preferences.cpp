--- src/lib/Preferences.cpp.orig	Tue Apr 11 22:40:59 2006
+++ src/lib/Preferences.cpp	Tue Apr 11 22:41:05 2006
@@ -81,7 +81,6 @@
 	else {
 		m_ladspaPathVect.push_back( "/usr/lib/ladspa" );
 		m_ladspaPathVect.push_back( string( CONFIG_PREFIX ).append( "/lib/hydrogen/plugins" ) );
-		m_ladspaPathVect.push_back( "/usr/local/lib/ladspa" );
 	}
 
 	m_pDefaultUIStyle = new UIStyle();
