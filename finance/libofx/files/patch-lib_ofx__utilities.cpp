--- lib/ofx_utilities.cpp.orig	2013-04-16 19:50:51 UTC
+++ lib/ofx_utilities.cpp
@@ -115,6 +115,11 @@ time_t ofxdate_to_time_t(const string ofxdate)
   char time_zone_specified = false;
   string ofxdate_whole;
   time_t temptime;
+  int daylight = 0;
+
+  tzset();
+  if(tzname[1][0] != ' ')
+    daylight = 1;
 
   time.tm_isdst = daylight; // initialize dst setting
   std::time(&temptime);
