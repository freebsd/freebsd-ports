$FreeBSD$

--- src/celestia/gtkmain.cpp.orig	Thu May  2 11:02:50 2002
+++ src/celestia/gtkmain.cpp	Tue May 21 03:55:01 2002
@@ -270,17 +270,8 @@
 
 static gint menuShowLocTime(GtkWidget* w, gpointer data)
 {
-    bool on = (appCore->getTimeZoneBias()==0);
-    if (on)
-    {
-        appCore->setTimeZoneBias(-timezone);
-        appCore->setTimeZoneName(tzname[daylight?0:1]);
-    }
-    else
-    {
-        appCore->setTimeZoneBias(0);
-        appCore->setTimeZoneName("UTC");
-    }
+    appCore->setTimeZoneBias(0);
+    appCore->setTimeZoneName("UTC");
     return TRUE;
 }
 
@@ -2058,9 +2049,8 @@
         appCore->start((double) curtime / 86400.0 + (double) astro::Date(1970, 1, 1));
 	localtime(&curtime); /* Only doing this to set timezone as a side
 			       effect*/
-	appCore->setTimeZoneBias(-timezone);
-	appCore->setTimeZoneName(tzname[daylight?0:1]);
-	timeOptions[1]=tzname[daylight?0:1];
+	appCore->setTimeZoneBias(localtime(&curtime)->tm_gmtoff);
+	appCore->setTimeZoneName(localtime(&curtime)->tm_zone);
     }
         
     return TRUE;
