--- src/celestia/kde/kdeapp.cpp.orig	2009-06-22 22:44:21
+++ src/celestia/kde/kdeapp.cpp	2009-08-17 22:04:54
@@ -1367,8 +1367,16 @@
         appCore->setTimeZoneBias(0);
         appCore->setTimeZoneName(i18n("UTC").latin1());
     } else {
+#if defined(__FreeBSD__)
+	/* FreeBSD does not export raw `timezone' and `daylight' values */
+	time_t curtime = time(NULL);
+	struct tm *temptime = localtime(&curtime);
+	appCore->setTimeZoneBias(temptime->tm_gmtoff);
+	appCore->setTimeZoneName(temptime->tm_zone);
+#else
         appCore->setTimeZoneBias(-timezone+3600*daylight);
         appCore->setTimeZoneName(tzname[daylight?0:1]);
+#endif
     }
 }
 
