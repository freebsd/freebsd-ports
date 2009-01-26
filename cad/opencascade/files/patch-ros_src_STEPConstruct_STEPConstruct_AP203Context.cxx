--- ./ros/src/STEPConstruct/STEPConstruct_AP203Context.cxx.orig	2001-09-21 10:00:28.000000000 +0200
+++ ./ros/src/STEPConstruct/STEPConstruct_AP203Context.cxx	2009-01-24 11:45:15.000000000 +0100
@@ -103,7 +103,7 @@
 
     Handle(StepBasic_CoordinatedUniversalTimeOffset) zone = 
       new StepBasic_CoordinatedUniversalTimeOffset;
-    Standard_Integer shift = Standard_Integer(timezone);
+    Standard_Integer shift = Standard_Integer((long long) timezone);
     Standard_Integer shifth = abs ( shift ) / 3600;
     Standard_Integer shiftm = ( abs ( shift ) - shifth * 3600 ) / 60;
     StepBasic_AheadOrBehind sense = ( shift >0 ? StepBasic_aobBehind : 
