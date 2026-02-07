--- components/safe_browsing/content/common/file_type_policies_unittest.cc.orig	2025-03-24 20:50:14 UTC
+++ components/safe_browsing/content/common/file_type_policies_unittest.cc
@@ -146,7 +146,7 @@ TEST_F(FileTypePoliciesTest, UnpackResourceBundle) {
   EXPECT_EQ(142, file_type.uma_value());
   EXPECT_FALSE(file_type.is_archive());
   EXPECT_EQ(DownloadFileType::FULL_PING, file_type.ping_setting());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(DownloadFileType::ALLOW_ON_USER_GESTURE,
             file_type.platform_settings(0).danger_level());
   EXPECT_EQ(DownloadFileType::DISALLOW_AUTO_OPEN,
