--- extensions/renderer/bindings/api_binding_util.cc.orig	2019-03-15 06:37:23 UTC
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -128,6 +128,8 @@ std::string GetPlatformString() {
   return "mac";
 #elif defined(OS_WIN)
   return "win";
+#elif defined(OS_BSD)
+  return "bsd";
 #else
   NOTREACHED();
   return std::string();
