--- core/parse-gpx.h.orig	2022-12-19 05:04:53 UTC
+++ core/parse-gpx.h
@@ -3,6 +3,7 @@
 #define PARSE_GPX_H
 
 #include <QString>
+#include <time.h>
 
 struct dive_coords {         // This structure holds important information after parsing the GPX file:
 	time_t start_dive;            // Start time of the current dive, obtained using current_dive (local time)
