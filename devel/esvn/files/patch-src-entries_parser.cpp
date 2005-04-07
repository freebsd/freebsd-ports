--- src/entries_parser.cpp	Thu Feb 24 08:15:56 2005
+++ src/entries_parser.cpp	Wed Mar 23 15:46:18 2005
@@ -246,14 +246,27 @@
 
 	int gm_sec  = isoDateTime.mid(17,2).toInt();
 
-	time_t utc_time = mktime(&m);
+	time_t utc_time;
 
+#if defined(__FreeBSD__)
+
+	// BSD has inverse of gmtime()
+	utc_time = timegm(&m);
+
+#else
+
+	// all others do mktime() and adjust timezone
 	// mktime assumes broken-down time in local timezone,
 	// to get UTC we need to correct result by timezone offset
+
+	utc_time = mktime(&m);
+
 #if (_WINDOWS || ESVN_WIN )
 	utc_time -= _timezone;
 #else
 	utc_time -= timezone;
+#endif
+
 #endif
 
 	// round to remove leap seconds in "right" timezones
