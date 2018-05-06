--- magproto.cc.orig	2018-04-11 18:16:46 UTC
+++ magproto.cc
@@ -819,11 +819,11 @@ mag_rd_init_common(const QString& portna
    */
   QString exten = QFileInfo(curfname).suffix();
   if (exten.length() > 0) {
-    if (0 == exten.compare("upt", Qt::CaseInsensitive)) {
+    if (0 == exten.compare(QLatin1String("upt"), Qt::CaseInsensitive)) {
       extension_hint = WPTDATAMASK;
-    } else if (0 == exten.compare("log", Qt::CaseInsensitive)) {
+    } else if (0 == exten.compare(QLatin1String("log"), Qt::CaseInsensitive)) {
       extension_hint = TRKDATAMASK;
-    } else if (0 == exten.compare("rte", Qt::CaseInsensitive)) {
+    } else if (0 == exten.compare(QLatin1String("rte"), Qt::CaseInsensitive)) {
       extension_hint = RTEDATAMASK;
     }
   }
