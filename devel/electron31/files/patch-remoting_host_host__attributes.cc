--- remoting/host/host_attributes.cc.orig	2024-06-18 21:43:37 UTC
+++ remoting/host/host_attributes.cc
@@ -105,7 +105,7 @@ std::string GetHostAttributes() {
   if (media::InitializeMediaFoundation()) {
     result.push_back("HWEncoder");
   }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   result.push_back("HWEncoder");
 #endif
 
