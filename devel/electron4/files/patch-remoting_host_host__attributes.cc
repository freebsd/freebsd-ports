--- remoting/host/host_attributes.cc.orig	2019-03-15 06:37:31 UTC
+++ remoting/host/host_attributes.cc
@@ -122,7 +122,7 @@ std::string GetHostAttributes() {
       media::InitializeMediaFoundation()) {
     result.push_back("HWEncoder");
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   result.push_back("HWEncoder");
 #endif
 
