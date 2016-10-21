--- lib/ofx_utilities.cpp.orig	2013-04-16 19:50:51 UTC
+++ lib/ofx_utilities.cpp
@@ -115,9 +115,14 @@ time_t ofxdate_to_time_t(const string of
   char time_zone_specified = false;
   string ofxdate_whole;
   time_t temptime;
+  int daylight;
+  const struct tm* t;
+  
+  std::time(&temptime);
+  t = localtime(&temptime);
+  daylight = t->tm_isdst;
 
   time.tm_isdst = daylight; // initialize dst setting
-  std::time(&temptime);
   local_offset = difftime(mktime(localtime(&temptime)), mktime(gmtime(&temptime))) + (3600 * daylight);
 
   if (ofxdate.size() != 0)
