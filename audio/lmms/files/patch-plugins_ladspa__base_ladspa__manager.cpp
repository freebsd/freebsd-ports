--- plugins/ladspa_base/ladspa_manager.cpp.orig	Mon Dec  4 15:22:27 2006
+++ plugins/ladspa_base/ladspa_manager.cpp	Mon Dec  4 16:06:22 2006
@@ -63,12 +63,11 @@
 					configManager::inst()->ladspaDir() );
 #endif
 	
-	ladspaDirectories.push_back( "/usr/lib/lmms/ladspa" );
+	ladspaDirectories.push_back( "@PREFIX@/lib/lmms/ladspa" );
 /*	// set default-directory if nothing is specified...
 	if( ladspaDirectories.isEmpty() )
 	{*/
-		ladspaDirectories.push_back( "/usr/lib/ladspa" );
-		ladspaDirectories.push_back( "/usr/local/lib/ladspa" );
+		ladspaDirectories.push_back( "@LOCALBASE@/lib/ladspa" );
 //	}
 	for( QStringList::iterator it = ladspaDirectories.begin(); 
 		    it != ladspaDirectories.end(); ++it )
