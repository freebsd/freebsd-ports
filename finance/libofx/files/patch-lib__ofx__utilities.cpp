--- ./lib/ofx_utilities.cpp.orig	2011-04-18 11:51:21.000000000 -0400
+++ ./lib/ofx_utilities.cpp	2011-06-01 21:09:51.000000000 -0400
@@ -115,9 +115,14 @@
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
