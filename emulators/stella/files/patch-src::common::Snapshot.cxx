--- src/common/Snapshot.cxx.orig	Wed Jun 23 09:15:32 2004
+++ src/common/Snapshot.cxx	Thu Sep 30 21:01:54 2004
@@ -73,7 +73,11 @@
   uInt32 width  = myFrameBuffer.imageWidth();
   uInt32 height = myFrameBuffer.imageHeight();
 
+#if defined(__GNUC__) && __GNUC__ < 3
+  ofstream* out = new ofstream(filename.c_str(), ios::binary);
+#else
   ofstream* out = new ofstream(filename.c_str(), ios_base::binary);
+#endif
   if(!out)
     return "Couldn't create snapshot file";
 
