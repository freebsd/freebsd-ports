--- remoting/host/host_details.cc.orig	2019-04-08 08:18:26 UTC
+++ remoting/host/host_details.cc
@@ -24,7 +24,7 @@ std::string GetHostOperatingSystemName() {
   return "Mac";
 #elif defined(OS_CHROMEOS)
   return "ChromeOS";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return "Linux";
 #elif defined(OS_ANDROID)
   return "Android";
