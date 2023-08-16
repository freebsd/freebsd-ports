--- src/misc/clocks.cpp.orig	2013-02-10 06:35:02 UTC
+++ src/misc/clocks.cpp
@@ -303,6 +303,9 @@ int get_timezone_offset()
 {
 #ifdef __APPLE__
 	int ret = [[NSTimeZone localTimeZone] secondsFromGMT];
+#elif defined(__FreeBSD__)
+	time_t date = time(NULL);
+	int ret = localtime(&date)->tm_gmtoff;
 #else
 	tzset();
 
