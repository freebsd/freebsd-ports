--- ktrack/predictionlist.cpp.orig	Wed Feb 22 19:58:26 2006
+++ ktrack/predictionlist.cpp	Wed Feb 22 19:58:39 2006
@@ -132,7 +132,7 @@
 /** No descriptions */
 double predictionList::qDateTime2daynum(QDateTime date){
   struct tm TM;
-  extern int daylight;
+//  extern int daylight;
   tzset();
 
   TM.tm_sec=date.time().second();
@@ -141,7 +141,7 @@
   TM.tm_mday=date.date().day();
   TM.tm_mon=date.date().month()-1;
   TM.tm_year=date.date().year()-1900;
-  TM.tm_isdst=daylight;
+  TM.tm_isdst=0; // daylight;
   time_t t = mktime(&TM);
 
 //  gmtime_r(&t, &TM);
