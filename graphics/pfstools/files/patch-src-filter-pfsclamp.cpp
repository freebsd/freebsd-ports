--- src/filter/pfsclamp.cpp.orig	2005-11-02 13:35:42.000000000 +0000
+++ src/filter/pfsclamp.cpp	2014-02-20 19:04:01.556587853 +0000
@@ -151,8 +151,8 @@
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
