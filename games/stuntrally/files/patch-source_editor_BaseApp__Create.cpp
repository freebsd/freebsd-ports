--- source/editor/BaseApp_Create.cpp.orig	2022-11-11 19:35:22 UTC
+++ source/editor/BaseApp_Create.cpp
@@ -240,7 +240,7 @@ bool BaseApp::setup()
 		#endif
 	}
 	#ifdef _DEBUG
-	Ogre::LogManager::getSingleton().setMinLogLevel(LML_TRIVIAL);  // all
+	//Ogre::LogManager::getSingleton().setMinLogLevel(LML_TRIVIAL);  // all
 	#endif
 
 	#ifdef _DEBUG
