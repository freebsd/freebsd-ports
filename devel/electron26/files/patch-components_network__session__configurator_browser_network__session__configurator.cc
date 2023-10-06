--- components/network_session_configurator/browser/network_session_configurator.cc.orig	2023-05-25 00:41:50 UTC
+++ components/network_session_configurator/browser/network_session_configurator.cc
@@ -808,7 +808,7 @@ net::URLRequestContextBuilder::HttpCacheParams::Type C
   }
 #endif  // #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE;
 #else
   return net::URLRequestContextBuilder::HttpCacheParams::DISK_BLOCKFILE;
