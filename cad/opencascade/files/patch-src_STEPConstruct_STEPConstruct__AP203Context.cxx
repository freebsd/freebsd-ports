--- src/STEPConstruct/STEPConstruct_AP203Context.cxx.orig	2012-02-16 07:33:16.000000000 +0100
+++ src/STEPConstruct/STEPConstruct_AP203Context.cxx	2012-02-16 07:33:39.000000000 +0100
@@ -103,7 +103,7 @@
 
     Handle(StepBasic_CoordinatedUniversalTimeOffset) zone = 
       new StepBasic_CoordinatedUniversalTimeOffset;
-    Standard_Integer shift = Standard_Integer(timezone);
+    Standard_Integer shift = Standard_Integer((long long)timezone);
     Standard_Integer shifth = abs ( shift ) / 3600;
     Standard_Integer shiftm = ( abs ( shift ) - shifth * 3600 ) / 60;
     StepBasic_AheadOrBehind sense = ( shift >0 ? StepBasic_aobBehind : 
