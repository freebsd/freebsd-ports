--- unix/ibus/mozc_engine.cc.org	2010-06-17 15:59:08.047320852 +0900
+++ unix/ibus/mozc_engine.cc	2010-06-26 16:32:23.046397317 +0900
@@ -66,7 +66,7 @@
 
 // Icon path for MozcTool
 // TODO(taku): currently, unknown icon is displayed.
-const char kMozcToolIconPath[] = "unknown.ico";
+const char kMozcToolIconPath[] = "toolicon_setting.png";
 
 // for every 5 minutes, call SyncData
 const uint64 kSyncDataInterval = 5 * 60;
