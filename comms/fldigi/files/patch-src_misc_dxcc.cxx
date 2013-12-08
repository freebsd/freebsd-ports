--- src/misc/dxcc.cxx.orig	2013-05-14 05:06:28.000000000 -0400
+++ src/misc/dxcc.cxx	2013-11-20 18:19:33.406394129 -0500
@@ -30,7 +30,7 @@
 #include <string>
 #include <list>
 #include <map>
-#include <tr1/unordered_map>
+#include <unordered_map>
 #include <algorithm>
 
 #include <FL/filename.H>
@@ -44,8 +44,11 @@
 #include "main.h"
 
 using namespace std;
-using tr1::unordered_map;
-
+//#ifdef __clang__
+using std::unordered_map;
+//#else
+//using tr1::unordered_map;
+//#endif
 
 dxcc::dxcc(const char* cn, int cq, int itu, const char* ct, float lat, float lon, float tz)
 	: country(cn), cq_zone(cq), itu_zone(itu), latitude(lat), longitude(lon), gmt_offset(tz)
