--- extensions/renderer/bindings/api_binding_util.cc.orig	2021-04-14 01:08:49 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -131,6 +131,8 @@ std::string GetPlatformString() {
   return "mac";
 #elif defined(OS_WIN)
   return "win";
+#elif defined(OS_BSD)
+  return "bsd";
 #else
   NOTREACHED();
   return std::string();
