--- krss/filterhandler.cpp.orig	Thu Oct 18 00:06:25 2001
+++ krss/filterhandler.cpp	Wed May 21 10:23:16 2003
@@ -29,6 +29,8 @@
 
 #include <iostream>
 
+using namespace std;
+
 FilterHandler::FilterHandler(FilterRule::Action defaultAction)
 {
 	mFilters.setAutoDelete(true);
