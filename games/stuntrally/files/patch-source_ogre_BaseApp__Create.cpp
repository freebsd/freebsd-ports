--- source/ogre/BaseApp_Create.cpp.orig	2022-11-11 19:35:22 UTC
+++ source/ogre/BaseApp_Create.cpp
@@ -177,12 +177,16 @@ BaseApp::~BaseApp()
 		mPlatform->shutdown();  delete mPlatform;  mPlatform = 0;  }
 
 	//  save inputs
-	mInputCtrl->save(PATHMANAGER::UserConfigDir() + "/input.xml");
-	delete mInputCtrl;
+	if (mInputCtrl) {
+		mInputCtrl->save(PATHMANAGER::UserConfigDir() + "/input.xml");
+		delete mInputCtrl;
+	}
 	for (int i=0; i<4; ++i)
 	{
-		mInputCtrlPlayer[i]->save(PATHMANAGER::UserConfigDir() + "/input_p" + toStr(i) + ".xml");
-		delete mInputCtrlPlayer[i];
+		if (mInputCtrlPlayer[i]) {
+			mInputCtrlPlayer[i]->save(PATHMANAGER::UserConfigDir() + "/input_p" + toStr(i) + ".xml");
+			delete mInputCtrlPlayer[i];
+		}
 	}
 
 	delete mInputWrapper;
@@ -326,7 +330,7 @@ bool BaseApp::setup()
 #endif
 
 	#ifdef _DEBUG
-	LogManager::getSingleton().setMinLogLevel(LML_TRIVIAL);  // all
+	//LogManager::getSingleton().setMinLogLevel(LML_TRIVIAL);  // all
 	#endif
 
 	setupResources();
