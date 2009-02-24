--- ./ros/src/STEPConstruct/STEPConstruct_AP203Context.cxx.orig	2001-09-21 10:00:28.000000000 +0200
+++ ./ros/src/STEPConstruct/STEPConstruct_AP203Context.cxx	2009-02-24 18:59:57.000000000 +0100
@@ -103,6 +103,13 @@
 
     Handle(StepBasic_CoordinatedUniversalTimeOffset) zone = 
       new StepBasic_CoordinatedUniversalTimeOffset;
+
+    struct tm newtime;
+    time_t ltime;
+    ltime=time(&ltime);
+    localtime_r(&ltime, &newtime);
+    int timezone=newtime.tm_gmtoff;
+
     Standard_Integer shift = Standard_Integer(timezone);
     Standard_Integer shifth = abs ( shift ) / 3600;
     Standard_Integer shiftm = ( abs ( shift ) - shifth * 3600 ) / 60;
