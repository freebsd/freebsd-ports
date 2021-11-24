--- remoting/host/host_attributes.cc.orig	2021-07-15 19:13:43 UTC
+++ remoting/host/host_attributes.cc
@@ -122,7 +122,7 @@ std::string GetHostAttributes() {
       media::InitializeMediaFoundation()) {
     result.push_back("HWEncoder");
   }
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   result.push_back("HWEncoder");
 #endif
 
