--- src/spot/pskrep.cxx.orig	2013-05-12 06:54:06.000000000 -0400
+++ src/spot/pskrep.cxx	2013-11-19 20:13:13.061879490 -0500
@@ -50,7 +50,11 @@
 #include <algorithm>
 #include <fstream>
 
-#if (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)
+#if __clang__
+#  define MAP_TYPE std::unordered_map
+#define HASH_TYPE std::hash
+#  include <unordered_map>
+#elif (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)
 #  define MAP_TYPE std::tr1::unordered_map
 #define HASH_TYPE std::tr1::hash
 #  include <tr1/unordered_map>
@@ -689,7 +693,7 @@
 		tlen = sizeof(long_station_info_template);
 		station_info = &long_station_info;
 	}
-	else if (template_count >= 0) {
+	else if (template_count != 0) {
 		station_info_template = short_station_info_template;
 		tlen = sizeof(short_station_info_template);
 		station_info = &short_station_info;
