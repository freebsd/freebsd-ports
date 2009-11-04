--- src/mediadevices/itunes/itunesdevice.cpp.orig	2009-11-04 22:07:06.000000000 +0100
+++ src/mediadevices/itunes/itunesdevice.cpp	2009-11-04 22:07:12.000000000 +0100
@@ -589,8 +589,9 @@
             //HACK
         #ifdef WIN32
             QDir qcd = m_path;
-        #endif
             QSettings().setValue( "devicePaths/" + uid + "/path", qcd.absolutePath() );
+        #endif
+
             //HACK
         }
         else
