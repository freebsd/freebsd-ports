--- tef_xml.cc.orig	2018-04-11 18:10:39 UTC
+++ tef_xml.cc
@@ -72,11 +72,11 @@
   bool valid = false;
 
   foreach(QXmlStreamAttribute attr, *attrv) {
-    if (attr.name().compare("Comment", Qt::CaseInsensitive) == 0) {
-      if (attr.value().compare("TourExchangeFormat", Qt::CaseInsensitive) == 0) {
+    if (attr.name().compare(QLatin1String("Comment"), Qt::CaseInsensitive) == 0) {
+      if (attr.value().compare(QLatin1String("TourExchangeFormat"), Qt::CaseInsensitive) == 0) {
         valid = true;
       }
-    } else if (attr.name().compare("Version", Qt::CaseInsensitive) == 0) {
+    } else if (attr.name().compare(QLatin1String("Version"), Qt::CaseInsensitive) == 0) {
       version = attr.value().toString().toDouble();
     }
   }
@@ -95,9 +95,9 @@
 {
   route = route_head_alloc();
   foreach(QXmlStreamAttribute attr, *attrv) {
-    if (attr.name().compare("Name", Qt::CaseInsensitive) == 0) {
+    if (attr.name().compare(QLatin1String("Name"), Qt::CaseInsensitive) == 0) {
       route->rte_name = attr.value().toString().trimmed();
-    } else if (attr.name().compare("Software", Qt::CaseInsensitive) == 0) {
+    } else if (attr.name().compare(QLatin1String("Software"), Qt::CaseInsensitive) == 0) {
       route->rte_desc = attr.value().toString().trimmed();
     }
   }
@@ -248,20 +248,20 @@
     QString attrstr = attr.value().toString();
     QByteArray attrtext = attrstr.toUtf8();
 
-    if (attr.name().compare("SegDescription", Qt::CaseInsensitive) == 0) {
+    if (attr.name().compare(QLatin1String("SegDescription"), Qt::CaseInsensitive) == 0) {
       wpt_tmp->shortname = attrstr.trimmed();
-    } else if (attr.name().compare("PointDescription", Qt::CaseInsensitive) == 0) {
+    } else if (attr.name().compare(QLatin1String("PointDescription"), Qt::CaseInsensitive) == 0) {
       wpt_tmp->description = attrstr.trimmed();
-    } else if (attr.name().compare("ViaStation", Qt::CaseInsensitive) == 0 &&
-               attr.value().compare("true", Qt::CaseInsensitive) == 0) {
+    } else if (attr.name().compare(QLatin1String("ViaStation"), Qt::CaseInsensitive) == 0 &&
+               attr.value().compare(QLatin1String("true"), Qt::CaseInsensitive) == 0) {
       wpt_tmp->wpt_flags.fmt_use = 1;  /* only a flag */
 
       /* new in TEF V2 */
-    } else if (attr.name().compare("Instruction", Qt::CaseInsensitive) == 0) {
+    } else if (attr.name().compare(QLatin1String("Instruction"), Qt::CaseInsensitive) == 0) {
       wpt_tmp->description = attrstr.trimmed();
-    } else if (attr.name().compare("Altitude", Qt::CaseInsensitive) == 0) {
+    } else if (attr.name().compare(QLatin1String("Altitude"), Qt::CaseInsensitive) == 0) {
       wpt_tmp->altitude = attrstr.toDouble();
-    } else if (attr.name().compare("TimeStamp", Qt::CaseInsensitive) == 0) {
+    } else if (attr.name().compare(QLatin1String("TimeStamp"), Qt::CaseInsensitive) == 0) {
       /* nothing for the moment */
     }
   }
