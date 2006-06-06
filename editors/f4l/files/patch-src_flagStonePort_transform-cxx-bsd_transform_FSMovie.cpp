--- src/flagStonePort/transform-cxx-bsd/transform/FSMovie.cpp.orig	Tue May 30 00:22:32 2006
+++ src/flagStonePort/transform-cxx-bsd/transform/FSMovie.cpp	Tue May 30 00:22:22 2006
@@ -1090,7 +1090,7 @@
         swfOut->setContext(FSStream::Version, version);
         swfOut->setListener(listener);
 
-        int numberOfBytes = 14 + frameSize.lengthInStream(swfOut);\
+        int numberOfBytes = 14 + frameSize.lengthInStream(swfOut);
         int objectLength = 0;
         
         for (FSVector<FSMovieObject*>::iterator i = objects.begin(); i != objects.end(); ++i)

