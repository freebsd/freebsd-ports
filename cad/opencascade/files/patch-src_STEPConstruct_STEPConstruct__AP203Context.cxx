--- src/STEPConstruct/STEPConstruct_AP203Context.cxx.orig	2025-02-17 22:00:23 UTC
+++ src/STEPConstruct/STEPConstruct_AP203Context.cxx
@@ -110,7 +110,15 @@ Handle(StepBasic_DateAndTime) STEPConstruct_AP203Conte
     long shift = 0;
     _get_timezone(&shift);
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
     Standard_Integer        shifth = abs(shift) / 3600;
     Standard_Integer        shiftm = (abs(shift) - shifth * 3600) / 60;
