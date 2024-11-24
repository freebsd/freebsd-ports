# this is a terrible hack - you can but should not copy this -- cmt
--- 3d-viewer/3d_cache/3d_cache.cpp.orig
+++ 3d-viewer/3d_cache/3d_cache.cpp
@@ -381,14 +381,17 @@
         dblock.process_bytes( block, bsize );
 
     fclose( fp );
-    unsigned int digest[5];
-    dblock.get_digest( digest );
+    union {
+        unsigned int digest[5];
+        unsigned char boost_digest[20];
+    } _digest;
+    dblock.get_digest( _digest.boost_digest );
 
     // ensure MSB order
     for( int i = 0; i < 5; ++i )
     {
         int idx = i << 2;
-        unsigned int tmp = digest[i];
+        unsigned int tmp = _digest.digest[i];
         aSHA1Sum[idx+3] = tmp & 0xff;
         tmp >>= 8;
         aSHA1Sum[idx+2] = tmp & 0xff;
