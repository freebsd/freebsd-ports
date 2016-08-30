--- exif.cc.orig	2016-01-03 02:09:17 UTC
+++ exif.cc
@@ -1100,7 +1100,7 @@ exif_find_wpt_by_time(const Waypoint* wp
 
   if (exif_wpt_ref == NULL) {
     exif_wpt_ref = wpt;
-  } else if (abs(exif_time_ref - wpt->creation_time.toTime_t()) < abs(exif_time_ref - exif_wpt_ref->creation_time.toTime_t())) {
+  } else if (qAbs(exif_time_ref - wpt->creation_time.toTime_t()) < qAbs(exif_time_ref - exif_wpt_ref->creation_time.toTime_t())) {
     exif_wpt_ref = wpt;
   }
 }
@@ -1447,12 +1447,12 @@ exif_write(void)
 
     if (exif_wpt_ref == NULL) {
       warning(MYNAME ": No point with a valid timestamp found.\n");
-    } else if (abs(exif_time_ref - exif_wpt_ref->creation_time.toTime_t()) > frame) {
+    } else if (qAbs(exif_time_ref - exif_wpt_ref->creation_time.toTime_t()) > frame) {
       warning(MYNAME ": No matching point found for image date %s!\n", qPrintable(str));
       if (exif_wpt_ref != NULL) {
         QString str = exif_time_str(exif_wpt_ref->creation_time.toTime_t());
         warning(MYNAME ": Best is from %s, %d second(s) away.\n",
-                qPrintable(str), abs(exif_time_ref - exif_wpt_ref->creation_time.toTime_t()));
+                qPrintable(str), (int) qAbs(exif_time_ref - exif_wpt_ref->creation_time.toTime_t()));
       }
       exif_wpt_ref = NULL;
     }
