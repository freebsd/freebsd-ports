--- src/globals.cpp.orig	Sat Apr  3 15:11:45 2004
+++ src/globals.cpp	Sat Apr  3 15:12:26 2004
@@ -172,7 +172,7 @@
 #ifdef USE_TM_GMTOFF
       timeZoneDiffInSecs = -(result->tm_gmtoff);
 #else
-      timeZoneDiffInSecs = timezone;
+      timeZoneDiffInSecs = (int)timezone;
 #endif
    }
    TIMEZERO.setTime_t(0);//ATTENTION: this is different from QDateTime()
