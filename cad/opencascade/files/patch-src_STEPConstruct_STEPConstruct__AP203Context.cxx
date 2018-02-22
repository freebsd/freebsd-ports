--- src/STEPConstruct/STEPConstruct_AP203Context.cxx.orig	2017-08-30 13:28:30 UTC
+++ src/STEPConstruct/STEPConstruct_AP203Context.cxx
@@ -123,7 +123,15 @@ Handle(StepBasic_DateAndTime) STEPConstr
     long shift = 0;
     _get_timezone (&shift);
   #else
-    Standard_Integer shift = Standard_Integer(timezone);
+    #if defined(__FreeBSD__)
+	struct tm *lt;
+	time_t t = 0;
+	time(&t);
+	lt = localtime(&t);
+	Standard_Integer shift = Standard_Integer(lt->tm_gmtoff);
+    #else
+      Standard_Integer shift = Standard_Integer(timezone);
+    #endif
   #endif
     Standard_Integer shifth = abs ( shift ) / 3600;
     Standard_Integer shiftm = ( abs ( shift ) - shifth * 3600 ) / 60;
