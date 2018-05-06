--- gpx.cc.orig	2018-04-11 18:10:39 UTC
+++ gpx.cc
@@ -494,7 +494,7 @@
 {
   cache_descr_is_html = 0;
   if (attr.hasAttribute("html")) {
-    if (attr.value("html").toString().compare("True") == 0) {
+    if (attr.value("html").compare(QLatin1String("True")) == 0) {
       cache_descr_is_html = 1;
     }
   }
@@ -509,16 +509,16 @@
     gc_data->id = attr.value("id").toString().toInt();
   }
   if (attr.hasAttribute("available")) {
-    if (attr.value("available").toString().compare("True", Qt::CaseInsensitive) == 0) {
+    if (attr.value("available").compare(QLatin1String("True"), Qt::CaseInsensitive) == 0) {
       gc_data->is_available = status_true;
-    } else if (attr.value("available").toString().compare("False", Qt::CaseInsensitive) == 0) {
+    } else if (attr.value("available").compare(QLatin1String("False"), Qt::CaseInsensitive) == 0) {
       gc_data->is_available = status_false;
     }
   }
   if (attr.hasAttribute("archived")) {
-    if (attr.value("archived").toString().compare("True", Qt::CaseInsensitive) == 0) {
+    if (attr.value("archived").compare(QLatin1String("True"), Qt::CaseInsensitive) == 0) {
       gc_data->is_archived = status_true;
-    } else if (attr.value("archived").toString().compare("False", Qt::CaseInsensitive) == 0) {
+    } else if (attr.value("archived").compare(QLatin1String("False"), Qt::CaseInsensitive) == 0) {
       gc_data->is_archived = status_false;
     }
   }
@@ -972,7 +972,7 @@
      * last date we saw in this log.
      */
   case tt_cache_log_type:
-    if ((cdatastr.compare("Found it") == 0) &&
+    if ((cdatastr.compare(QLatin1String("Found it")) == 0) &&
         (0 == wpt_tmp->gc_data->last_found.toTime_t())) {
       wpt_tmp->AllocGCData()->last_found = gc_log_date;
     }
@@ -1423,7 +1423,7 @@
         fprint_xml_chain(tag->child, wpt);
       }
       if (wpt && wpt->gc_data->exported.isValid() &&
-          tag->tagname.compare("groundspeak:cache") == 0) {
+          tag->tagname.compare(QLatin1String("groundspeak:cache")) == 0) {
         writer->writeTextElement("time",
                                  wpt->gc_data->exported.toPrettyString());
       }
