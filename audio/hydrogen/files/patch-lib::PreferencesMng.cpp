--- lib/PreferencesMng.cpp.orig	Sun Aug 15 18:53:34 2004
+++ lib/PreferencesMng.cpp	Sun Aug 15 18:53:45 2004
@@ -70,7 +70,6 @@
 	}
 	else {
 		m_ladspaPathVect.push_back("/usr/lib/ladspa");
-		m_ladspaPathVect.push_back("/usr/local/lib/ladspa");
 	}
 	
 	recordEvents = false;
