--- remoting/host/host_attributes.cc.orig	2019-09-10 11:14:11 UTC
+++ remoting/host/host_attributes.cc
@@ -123,7 +123,7 @@ std::string GetHostAttributes() {
       media::InitializeMediaFoundation()) {
     result.push_back("HWEncoder");
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   result.push_back("HWEncoder");
 #endif
 
