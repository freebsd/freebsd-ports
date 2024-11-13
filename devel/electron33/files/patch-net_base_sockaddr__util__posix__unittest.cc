--- net/base/sockaddr_util_posix_unittest.cc.orig	2024-08-14 20:55:08 UTC
+++ net/base/sockaddr_util_posix_unittest.cc
@@ -88,7 +88,8 @@ TEST(FillUnixAddressTest, AbstractLinuxAddress) {
   size_t path_max = MaxPathLength(&storage);
   std::string path(path_max, '0');
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+  // XXX?
   EXPECT_TRUE(FillUnixAddress(path, /*use_abstract_namespace=*/true, &storage));
 
   EXPECT_EQ(path.size() + 1U + offsetof(struct sockaddr_un, sun_path),
