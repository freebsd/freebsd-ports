--- extensions/renderer/bindings/api_binding_util.cc.orig	2019-09-10 10:42:38 UTC
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
