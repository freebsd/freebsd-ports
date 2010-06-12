--- unix/ibus/mozc_engine.cc.org	2010-06-11 18:00:39.000000000 +0900
+++ unix/ibus/mozc_engine.cc	2010-06-12 13:19:26.188760964 +0900
@@ -59,7 +59,7 @@
 
 // Icon path for MozcTool
 // TODO(taku): currently, unknown icon is displayed.
-const char kMozcToolIconPath[] = "unknown.ico";
+const char kMozcToolIconPath[] = "toolicon_setting.png";
 
 // for every 5 minutes, call SyncData
 const uint64 kSyncDataInterval = 5 * 60;
