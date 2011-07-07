--- Source/DataDictionary/gdcmGlobal.cxx.orig	2011-07-07 09:11:27.000000000 +0200
+++ Source/DataDictionary/gdcmGlobal.cxx	2011-07-07 09:11:56.000000000 +0200
@@ -45,7 +45,7 @@
   void LoadDefaultPaths()
     {
     assert( RessourcePaths.empty() );
-    const char filename2[] = GDCM_CMAKE_INSTALL_PREFIX "/" GDCM_INSTALL_DATA_DIR "/XML/";
+    const char filename2[] = GDCM_INSTALL_DATA_DIR "/XML/";
     RessourcePaths.push_back( filename2 );
     const char *curprocfn = System::GetCurrentProcessFileName();
     if( curprocfn )
