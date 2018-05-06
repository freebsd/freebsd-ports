--- unicsv.cc.orig	2018-04-11 18:21:19 UTC
+++ unicsv.cc
@@ -430,13 +430,13 @@ unicsv_parse_time(const QString& str, in
 static status_type
 unicsv_parse_status(const QString& str)
 {
-  if (str.compare("true", Qt::CaseInsensitive) == 0 ||
-      str.compare("yes", Qt::CaseInsensitive) == 0 ||
+  if (str.compare(QLatin1String("true"), Qt::CaseInsensitive) == 0 ||
+      str.compare(QLatin1String("yes"), Qt::CaseInsensitive) == 0 ||
       str == "1") {
     return status_true;
   }
-  if (str.compare("false", Qt::CaseInsensitive) == 0 ||
-      str.compare("no", Qt::CaseInsensitive) == 0 ||
+  if (str.compare(QLatin1String("false"), Qt::CaseInsensitive) == 0 ||
+      str.compare(QLatin1String("no"), Qt::CaseInsensitive) == 0 ||
       str == "0") {
     return status_false;
   }
