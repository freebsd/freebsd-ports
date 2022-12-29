--- base/system/sys_info_unittest.cc.orig	2022-09-24 10:57:32 UTC
+++ base/system/sys_info_unittest.cc
@@ -234,12 +234,16 @@ TEST_F(SysInfoTest, GetHardwareInfo) {
   EXPECT_TRUE(IsStringUTF8(hardware_info->model));
   bool empty_result_expected =
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
       false;
 #else
       true;
 #endif
   EXPECT_EQ(hardware_info->manufacturer.empty(), empty_result_expected);
+#if BUILDFLAG(IS_BSD)
+  empty_result_expected = true;
+#endif
   EXPECT_EQ(hardware_info->model.empty(), empty_result_expected);
 }
 
