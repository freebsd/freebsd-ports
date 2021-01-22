--- extensions/renderer/bindings/api_binding_util.cc.orig	2020-05-26 08:03:23 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -129,6 +129,8 @@ std::string GetPlatformString() {
   return "mac";
 #elif defined(OS_WIN)
   return "win";
+#elif defined(OS_BSD)
+  return "bsd";
 #else
   NOTREACHED();
   return std::string();
