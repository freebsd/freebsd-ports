--- src/base/system_util.cc.orig	2015-02-17 17:59:05.000000000 +0900
+++ src/base/system_util.cc	2015-02-17 18:01:50.000000000 +0900
@@ -407,7 +407,11 @@
   if (server_path.empty()) {
     return "";
   }
+#ifdef MOZC_RENDERER_DIRECTORY
+  return FileUtil::JoinPath(MOZC_RENDERER_DIRECTORY "/", kMozcRenderer);
+#else
   return FileUtil::JoinPath(server_path, kMozcRenderer);
+#endif
 }
 
 string SystemUtil::GetToolPath() {
@@ -416,7 +420,11 @@
   if (server_path.empty()) {
     return "";
   }
+#ifdef MOZC_TOOL_DIRECTORY
+  return FileUtil::JoinPath(MOZC_TOOL_DIRECTORY "/", kMozcTool);
+#else
   return FileUtil::JoinPath(server_path, kMozcTool);
+#endif
 }
 
 string SystemUtil::GetDocumentDirectory() {
