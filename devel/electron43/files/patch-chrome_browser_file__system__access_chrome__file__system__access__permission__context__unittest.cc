--- chrome/browser/file_system_access/chrome_file_system_access_permission_context_unittest.cc.orig	2026-11-13 08:10:02 UTC
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context_unittest.cc
@@ -669,7 +669,7 @@ TEST_F(ChromeFileSystemAccessPermissionContextTest,
        ConfirmSensitiveEntryAccess_HomeCacheBlockedOnAllPlatforms) {
   base::FilePath home_dir = temp_dir_.GetPath().AppendASCII("home");
   ScopedHomeDirOverride home_override = OverrideHomeDir(home_dir);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   base::FilePath xdg_cache_dir = temp_dir_.GetPath().AppendASCII("xdg_cache");
   base::ScopedPathOverride cache_override(base::DIR_CACHE, xdg_cache_dir, true,
                                           true);
@@ -697,7 +697,7 @@ TEST_F(ChromeFileSystemAccessPermissionContextTest,
                 HandleType::kFile, AccessTrigger::kProgrammaticWrite),
             SensitiveDirectoryResult::kAbort);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Custom $XDG_CACHE_HOME / Android cache directory remains blocked too.
   EXPECT_TRUE(IsOpenAbort(xdg_cache_dir, HandleType::kDirectory));
   EXPECT_TRUE(IsOpenAbort(xdg_cache_dir.AppendASCII("foo"), HandleType::kFile));
@@ -828,7 +828,7 @@ TEST_F(ChromeFileSystemAccessPermissionContextTest,
 TEST_F(ChromeFileSystemAccessPermissionContextTest,
        ConfirmSensitiveEntryAccess_ExplicitPathBlock) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // /dev should be blocked.
   EXPECT_EQ(ConfirmSensitiveEntryAccessSync(
                 permission_context(), PathInfo(FILE_PATH_LITERAL("/dev")),
@@ -1560,7 +1560,7 @@ TEST_F(ChromeFileSystemAccessPermissionContextTest,
        false},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
       {kNoBasePathKey, FILE_PATH_LITERAL("/dev"), true, false},
       {kNoBasePathKey, FILE_PATH_LITERAL("/proc"), true, false},
       {kNoBasePathKey, FILE_PATH_LITERAL("/sys"), true, false},
