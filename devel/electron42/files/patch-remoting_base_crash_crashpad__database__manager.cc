--- remoting/base/crash/crashpad_database_manager.cc.orig	2026-04-28 21:06:17 UTC
+++ remoting/base/crash/crashpad_database_manager.cc
@@ -23,7 +23,7 @@
 #if BUILDFLAG(IS_WIN)
 #include "base/base_paths.h"
 #include "base/strings/utf_string_conversions.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -38,7 +38,7 @@ namespace {
 namespace remoting {
 namespace {
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const base::FilePath::CharType kChromotingCrashpadDatabasePath[] =
     FILE_PATH_LITERAL("crashpad");
 #endif
@@ -55,7 +55,7 @@ const size_t kMaxReportAgeDays = 7;
 // Maximum number of days to keep reports around in the local database.
 const size_t kMaxReportAgeDays = 7;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 inline base::FilePath GetDaemonProcessCrashpadDatabasePath() {
   return GetVarLibDir().Append("crashpad.daemon");
@@ -129,7 +129,7 @@ base::FilePath GetCrashpadDatabasePath() {
   base::FilePath database_path;
   base::PathService::Get(base::BasePathKey::DIR_ASSETS, &database_path);
   return database_path.Append(kChromotingCrashpadDatabasePath);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (getuid() == 0) {
     return GetDaemonProcessCrashpadDatabasePath();
   }
@@ -161,7 +161,7 @@ bool CrashpadDatabaseManager::InitializeCrashpadDataba
 CrashpadDatabaseManager::~CrashpadDatabaseManager() = default;
 
 bool CrashpadDatabaseManager::InitializeCrashpadDatabase() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   SetupCrashpadDirectories();
 #endif
 
