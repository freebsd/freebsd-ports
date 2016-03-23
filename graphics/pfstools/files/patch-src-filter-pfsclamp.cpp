--- src/filter/pfsclamp.cpp.orig	2005-11-02 13:35:42 UTC
+++ src/filter/pfsclamp.cpp
@@ -151,8 +151,8 @@ void clampFrames( int argc, char* argv[]
   }
   else
   {
-    clampMin = (clampMin>1e-4) ? clampMin : 1e-4;
-    clampMax = (clampMax<1e8) ? clampMax : 1e8;
+    clampMin = (clampMin>1e-20) ? clampMin : 1e-20;
+    clampMax = (clampMax<1e+20) ? clampMax : 1e+20;
     if( clampMin >= clampMax )
       throw pfs::Exception("incorrect clamping range");
   }
