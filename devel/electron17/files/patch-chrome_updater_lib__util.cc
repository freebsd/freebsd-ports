--- chrome/updater/lib_util.cc.orig	2022-05-11 07:16:49 UTC
+++ chrome/updater/lib_util.cc
@@ -11,7 +11,7 @@
 
 namespace updater {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 std::string UnescapeURLComponent(base::StringPiece escaped_text) {
   return base::UnescapeURLComponent(
