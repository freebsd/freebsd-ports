--- src/celestia/kde/kdeglwidget.cpp.orig	2009-06-22 22:44:21
+++ src/celestia/kde/kdeglwidget.cpp	2009-08-17 13:30:31
@@ -106,9 +106,16 @@
 
     time_t curtime=time(NULL);
     appCore->start(astro::UTCtoTDB((double) curtime / 86400.0 + (double) astro::Date(1970, 1, 1)));
+#if defined(__FreeBSD__)
+    /* FreeBSD does not export raw `timezone' and `daylight' values */
+    struct tm *temptime = localtime(&curtime);
+    appCore->setTimeZoneBias(temptime->tm_gmtoff);
+    appCore->setTimeZoneName(temptime->tm_zone);
+#else
     localtime(&curtime); /* Only doing this to set timezone as a side effect*/
     appCore->setTimeZoneBias(-timezone+3600*daylight);
     appCore->setTimeZoneName(tzname[daylight?0:1]);
+#endif
     appCore->tick();
 
     KGlobal::config()->setGroup("Preferences");
