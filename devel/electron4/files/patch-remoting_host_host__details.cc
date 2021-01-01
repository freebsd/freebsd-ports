--- remoting/host/host_details.cc.orig	2019-03-15 06:37:31 UTC
+++ remoting/host/host_details.cc
@@ -22,7 +22,7 @@ std::string GetHostOperatingSystemName() {
   return "Mac";
 #elif defined(OS_CHROMEOS)
   return "ChromeOS";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return "Linux";
 #elif defined(OS_ANDROID)
   return "Android";
