--- src/misc/clocks.cpp.orig	2013-02-10 06:35:02 UTC
+++ src/misc/clocks.cpp
@@ -304,18 +304,8 @@ int get_timezone_offset()
 #ifdef __APPLE__
 	int ret = [[NSTimeZone localTimeZone] secondsFromGMT];
 #else
-	tzset();
-
-	// ::timezone's manpage says "Seconds West of GMT", but I found this not to be the case
-	// ::timezone is in the range [-12*3600, 12*3600], but it's sign is opposite what we expect:
-	//   Central Time is +6 hours
-	// We want to return -6 hours for Central, so we translate the range and ensure it's min and max value
-
-
-	int ret = ::timezone;
-
-	// invert sign for our purposes
-	ret = -ret;
+	time_t date = time(NULL);
+	int ret = localtime(&date)->tm_gmtoff;
 #endif
 	
 	// "clamp-and-shift" to convert values outside the appropriate
