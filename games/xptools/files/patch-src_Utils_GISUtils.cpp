--- src/Utils/GISUtils.cpp.orig	2017-11-07 02:12:22 UTC
+++ src/Utils/GISUtils.cpp
@@ -40,12 +40,7 @@
 // set to 1 to save geotiff inside geojp2 to disk
 #define DUMP_GTIF 0
 
-#if defined(IBM)
-	#include <libxtiff/xtiffio.h>
-	#include "GUI_Unicode.h"
-#else
 	#include <xtiffio.h>
-#endif
 void	make_cache_file_path(const char * cache_base, int west, int south, const char * cache_name, char path[1024])
 {
 	sprintf(path, "%s%s%+03d%+04d%s%+03d%+04d.%s.txt", cache_base, DIR_STR, latlon_bucket (south), latlon_bucket (west), DIR_STR, (int) south, (int) west, cache_name);
