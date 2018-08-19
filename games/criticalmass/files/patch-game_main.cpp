--- game/main.cpp.orig	2010-10-17 01:09:48 UTC
+++ game/main.cpp
@@ -139,9 +139,7 @@ void checkEndian( void)
 void showInfo()
 {
     LOG_INFO << "----------------------------------" << endl;
-    LOG_INFO << GAMETITLE << " " << GAMEVERSION 
-             << " - "__TIME__" "__DATE__
-             << endl;
+    LOG_INFO << GAMETITLE << " " << GAMEVERSION << endl;
     LOG_INFO << "Copyright (C) 2001-2010 by Frank Becker" << endl;
     LOG_INFO << "Visit http://criticalmass.sourceforge.net" << endl;
     LOG_INFO << "----------------------------------" << endl;
@@ -170,7 +168,6 @@ void showVersions( void)
              << (int)msdl->major  << "."
              << (int)msdl->minor  << "."
              << (int)msdl->patch  << endl;
-    LOG_INFO << "zlib Version " << zlibVersion() << endl;
     LOG_INFO << "PNG Version " << png_get_header_version(NULL) << endl;
 }
  
