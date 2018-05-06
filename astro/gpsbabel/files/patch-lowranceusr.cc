--- lowranceusr.cc.orig	2018-04-11 18:16:00 UTC
+++ lowranceusr.cc
@@ -767,7 +767,7 @@ lowranceusr_waypt_disp(const Waypoint* w
 
   gbfputint32(Time, file_out);
 
-  if (get_cache_icon(wpt) && wpt->icon_descr.compare("Geocache Found") == 0) {
+  if (get_cache_icon(wpt) && wpt->icon_descr.compare(QLatin1String("Geocache Found")) == 0) {
     SymbolId = lowranceusr_find_icon_number_from_desc(get_cache_icon(wpt));
   } else {
     SymbolId = lowranceusr_find_icon_number_from_desc(wpt->icon_descr);
