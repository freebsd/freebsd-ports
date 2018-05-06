--- psitrex.cc.orig	2018-04-11 18:17:53 UTC
+++ psitrex.cc
@@ -363,7 +363,7 @@ psit_waypoint_w(gbfile* psit_file, const
 
   icon = gt_find_icon_number_from_desc(wpt->icon_descr, PCX);
 
-  if (get_cache_icon(wpt) && wpt->icon_descr.compare("Geocache Found") != 0) {
+  if (get_cache_icon(wpt) && wpt->icon_descr.compare(QLatin1String("Geocache Found")) != 0) {
     icon = gt_find_icon_number_from_desc(get_cache_icon(wpt), PCX);
   }
 
