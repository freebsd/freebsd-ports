--- ./lib/ofx_utilities.cpp.orig	2011-02-12 11:51:02.000000000 -0500
+++ ./lib/ofx_utilities.cpp	2011-02-14 22:24:26.000000000 -0500
@@ -115,9 +115,10 @@
 
   time_t temptime;
 
-  time.tm_isdst = daylight; // iniitialize dst setting
+  bzero(&time, sizeof(time));
+
   std::time(&temptime);
-  local_offset = difftime(mktime(localtime(&temptime)), mktime(gmtime(&temptime))) + (3600*daylight);
+  local_offset = difftime(mktime(localtime(&temptime)), mktime(gmtime(&temptime)));
   
   if(ofxdate.size()!=0){
     if (ofxdate.substr(0,8).find_first_not_of("0123456789") != string::npos ){
