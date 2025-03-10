--- components/embedder_support/user_agent_utils_unittest.cc.orig	2024-06-18 21:43:28 UTC
+++ components/embedder_support/user_agent_utils_unittest.cc
@@ -71,7 +71,7 @@ const char kDesktop[] =
     "X11; CrOS x86_64 14541.0.0"
 #elif BUILDFLAG(IS_FUCHSIA)
     "Fuchsia"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "X11; Linux x86_64"
 #elif BUILDFLAG(IS_MAC)
     "Macintosh; Intel Mac OS X 10_15_7"
@@ -171,7 +171,7 @@ void CheckUserAgentStringOrdering(bool mobile_device) 
   ASSERT_EQ("CrOS", pieces[0]);
   ASSERT_EQ("x86_64", pieces[1]);
   ASSERT_EQ("14541.0.0", pieces[2]);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Post-UA Reduction there is a single <unifiedPlatform> value for Linux:
   // X11; Linux x86_64
   ASSERT_EQ(2u, pieces.size());
@@ -727,7 +727,7 @@ TEST_F(UserAgentUtilsTest, UserAgentMetadata) {
 #endif
 #elif BUILDFLAG(IS_ANDROID)
   EXPECT_EQ(metadata.platform, "Android");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(metadata.platform, "Linux");
 #elif BUILDFLAG(IS_FREEBSD)
   EXPECT_EQ(metadata.platform, "FreeBSD");
