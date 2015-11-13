--- src/STEPConstruct/STEPConstruct_AP203Context.cxx.orig	2015-09-25 16:19:10.000000000 +0200
+++ src/STEPConstruct/STEPConstruct_AP203Context.cxx	2015-10-25 20:37:31.000000000 +0100
@@ -105,7 +105,7 @@
     long shift = 0;
     _get_timezone (&shift);
   #else
-    Standard_Integer shift = Standard_Integer(timezone);
+    Standard_Integer shift = Standard_Integer((long long)timezone);
   #endif
     Standard_Integer shifth = abs ( shift ) / 3600;
     Standard_Integer shiftm = ( abs ( shift ) - shifth * 3600 ) / 60;
