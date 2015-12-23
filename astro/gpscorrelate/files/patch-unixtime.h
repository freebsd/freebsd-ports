--- unixtime.h.orig	2012-08-14 10:11:01 UTC
+++ unixtime.h
@@ -27,6 +27,7 @@
 
 #define EXIF_DATE_FORMAT "%d:%d:%d %d:%d:%d"
 #define GPX_DATE_FORMAT "%d-%d-%dT%d:%d:%dZ"
+#include <sys/types.h>
 
 time_t ConvertToUnixTime(char* StringTime, char* Format,
 		int TZOffsetHours, int TZOffsetMinutes);
