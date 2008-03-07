--- unixtime.h.orig	2008-02-18 12:50:16.000000000 +0100
+++ unixtime.h	2008-02-18 12:50:41.000000000 +0100
@@ -27,6 +27,7 @@
 
 #define EXIF_DATE_FORMAT "%d:%d:%d %d:%d:%d"
 #define GPX_DATE_FORMAT "%d-%d-%dT%d:%d:%dZ"
+#include <sys/types.h>
 
 time_t ConvertToUnixTime(char* StringTime, char* Format,
 		int TZOffsetHours, int TZOffsetMinutes);
