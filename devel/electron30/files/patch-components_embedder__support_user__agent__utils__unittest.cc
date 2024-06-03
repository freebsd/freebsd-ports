--- components/embedder_support/user_agent_utils_unittest.cc.orig	2023-10-19 19:58:18 UTC
+++ components/embedder_support/user_agent_utils_unittest.cc
@@ -84,7 +84,7 @@ const char kDesktop[] =
     "Safari/537.36";
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::string GetMachine() {
   struct utsname unixinfo;
   uname(&unixinfo);
@@ -192,7 +192,7 @@ void CheckUserAgentStringOrdering(bool mobile_device) 
     int value;
     ASSERT_TRUE(base::StringToInt(pieces[i], &value));
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // X11; Linux x86_64
   ASSERT_EQ(2u, pieces.size());
   ASSERT_EQ("X11", pieces[0]);
