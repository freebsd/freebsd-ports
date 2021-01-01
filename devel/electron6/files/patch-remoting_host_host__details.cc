--- remoting/host/host_details.cc.orig	2019-09-10 11:14:11 UTC
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
