--- src/STEPConstruct/STEPConstruct_AP203Context.cxx.orig	2016-11-25 09:52:26 UTC
+++ src/STEPConstruct/STEPConstruct_AP203Context.cxx
@@ -123,7 +123,7 @@ Handle(StepBasic_DateAndTime) STEPConstr
     long shift = 0;
     _get_timezone (&shift);
   #else
-    Standard_Integer shift = Standard_Integer(timezone);
+    Standard_Integer shift = Standard_Integer((long long)timezone);
   #endif
     Standard_Integer shifth = abs ( shift ) / 3600;
     Standard_Integer shiftm = ( abs ( shift ) - shifth * 3600 ) / 60;
