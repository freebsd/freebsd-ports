$FreeBSD$

author:  Jean-Yves Lefort

--- src/celestia/gtkmain.cpp.orig	Tue Feb 15 19:00:43 2005
+++ src/celestia/gtkmain.cpp	Tue Feb 15 19:16:55 2005
@@ -54,6 +54,10 @@
 
 using namespace std;
 
+// Linux compatibility
+static int daylight = 0;
+static long linux_timezone = 0;
+
 char AppName[] = "Celestia";
 
 static CelestiaCore* appCore = NULL;
@@ -274,7 +278,7 @@
 {
     if (appCore->getTimeZoneBias() == 0)
     {
-        appCore->setTimeZoneBias(-timezone + 3600 * daylight);
+        appCore->setTimeZoneBias(-linux_timezone + 3600 * daylight);
         appCore->setTimeZoneName(tzname[daylight]);
 		prefs->showLocalTime = TRUE;
     }
@@ -3391,7 +3395,7 @@
 	appCore->start((double) curtime / 86400.0 + (double) astro::Date(1970, 1, 1));
 	localtime(&curtime); /* Only doing this to set timezone as a side
 							effect*/
-	appCore->setTimeZoneBias(-timezone + 3600 * daylight);
+	appCore->setTimeZoneBias(-linux_timezone + 3600 * daylight);
 	appCore->setTimeZoneName(tzname[daylight]);
 	timeOptions[1]=tzname[daylight];
 
@@ -3967,7 +3971,7 @@
 	appCore->getRenderer()->setStarStyle(p->starStyle);
 	appCore->setHudDetail(p->hudDetail);
 	if (p->showLocalTime) {
-		appCore->setTimeZoneBias(-timezone + 3600 * daylight);
+		appCore->setTimeZoneBias(-linux_timezone + 3600 * daylight);
 		appCore->setTimeZoneName(tzname[daylight]);
 	}
 	else {
@@ -4067,7 +4071,7 @@
 void confShowLocalTime(GConfClient* c, guint, GConfEntry* e, gpointer) {
 	prefs->showLocalTime = gconf_client_get_bool(c, gconf_entry_get_key(e), NULL);
 	if (prefs->showLocalTime) {
-		appCore->setTimeZoneBias(-timezone + 3600 * daylight);
+		appCore->setTimeZoneBias(-linux_timezone + 3600 * daylight);
 		appCore->setTimeZoneName(tzname[daylight]);
 	}
 	else {
@@ -4126,6 +4130,18 @@
 // MAIN
 int main(int argc, char* argv[])
 {
+    time_t now;
+    struct tm *tm;
+
+    // provide Linux's daylight and timezone
+    now = time(NULL);
+    if (now >= 0)
+    {
+	tm = localtime(&now);
+	daylight = tm->tm_isdst;
+	linux_timezone = tm->tm_gmtoff;
+    }
+
     // Say we're not ready to render yet.
     bReady = false;
 
