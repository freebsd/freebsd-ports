--- korganizer/plugins/holidays/holidays.cpp.orig	Tue Nov  9 21:00:17 2004
+++ korganizer/plugins/holidays/holidays.cpp	Tue Nov  9 21:01:01 2004
@@ -91,7 +91,7 @@
   //static int lastYear = 0;
   int lastYear = 0;
 
-  if (mHolidayFile.isEmpty()) return QString::null;
+  if (mHolidayFile.isEmpty() || qd.isNull()) return QString::null;
 
   //if ((lastYear == 0) || (qd.year() != lastYear)) {
   if ((yearLast == 0) || (qd.year() != yearLast)) {
