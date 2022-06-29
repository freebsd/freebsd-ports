--- components/network_session_configurator/browser/network_session_configurator_unittest.cc.orig	2022-05-25 04:00:55 UTC
+++ components/network_session_configurator/browser/network_session_configurator_unittest.cc
@@ -807,7 +807,7 @@ TEST_F(NetworkSessionConfiguratorTest, HostRules) {
 }
 
 TEST_F(NetworkSessionConfiguratorTest, DefaultCacheBackend) {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE,
             ChooseCacheType());
 #elif BUILDFLAG(IS_MAC)
