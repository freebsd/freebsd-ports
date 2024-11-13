--- components/network_session_configurator/browser/network_session_configurator_unittest.cc.orig	2024-10-16 21:31:11 UTC
+++ components/network_session_configurator/browser/network_session_configurator_unittest.cc
@@ -855,7 +855,7 @@ TEST_F(NetworkSessionConfiguratorTest, DefaultCacheBac
 
 TEST_F(NetworkSessionConfiguratorTest, DefaultCacheBackend) {
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE,
             ChooseCacheType());
 #else
