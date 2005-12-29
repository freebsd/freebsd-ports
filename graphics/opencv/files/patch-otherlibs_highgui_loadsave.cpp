--- otherlibs/highgui/loadsave.cpp.orig Mon Feb 28 17:12:05 2005
+++ otherlibs/highgui/loadsave.cpp      Mon Feb 28 17:12:09 2005
@@ -299,7 +299,6 @@
     m_factories->AddFactory( new GrFmtJpeg() );
     m_factories->AddFactory( new GrFmtSunRaster() );
     m_factories->AddFactory( new GrFmtPxM() );
-    m_factories->AddFactory( new GrFmtTiff() );
 #ifdef HAVE_PNG
     m_factories->AddFactory( new GrFmtPng() );
 #endif

