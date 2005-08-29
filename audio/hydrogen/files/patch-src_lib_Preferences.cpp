--- src/lib/Preferences.cpp.orig	Mon Aug 29 01:08:31 2005
+++ src/lib/Preferences.cpp	Mon Aug 29 01:15:20 2005
@@ -80,7 +80,6 @@
 	}
 	else {
 		m_ladspaPathVect.push_back("/usr/lib/ladspa");
-		m_ladspaPathVect.push_back("/usr/local/lib/ladspa");
 	}
 
 	m_pDefaultUIStyle = new UIStyle();
