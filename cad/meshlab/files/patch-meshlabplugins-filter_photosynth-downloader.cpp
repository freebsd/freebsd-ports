Prevents the following build error:

downloader.cpp:686:23: error: non-constant-expression cannot be narrowed from type 'unsigned char' to 'char' in initializer list [-Wc++11-narrowing]
  char reversed[] = { bytes[3],bytes[2],bytes[1],bytes[0] };
                      ^~~~~~~~
downloader.cpp:686:23: note: insert an explicit cast to silence this issue
--- meshlabplugins/filter_photosynth/downloader.cpp.orig	2013-05-22 15:09:13 UTC
+++ meshlabplugins/filter_photosynth/downloader.cpp
@@ -683,7 +683,7 @@
     if(error)
       return -1;
   }
-  char reversed[] = { bytes[3],bytes[2],bytes[1],bytes[0] };
+  unsigned char reversed[] = { bytes[3],bytes[2],bytes[1],bytes[0] };
 
   float *f = (float *)(&  reversed[0]);
   return*f;
