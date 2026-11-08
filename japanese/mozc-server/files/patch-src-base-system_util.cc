--- src/base/system_util.cc.orig	2026-10-16 12:33:33 UTC
+++ src/base/system_util.cc
@@ -215,7 +215,7 @@ std::string UserProfileDirectoryImpl::GetUserProfileDi
     return FileUtil::JoinPath(dir, "Mozc");
 #endif  //  GOOGLE_JAPANESE_INPUT_BUILD
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     // 1. If "$HOME/.mozc" already exists,
     //    use "$HOME/.mozc" for backward compatibility.
     // 2. If $XDG_CONFIG_HOME is defined
@@ -313,7 +313,7 @@ std::string SystemUtil::GetServerDirectory() {
 #endif  // _WIN32
 
 std::string SystemUtil::GetServerDirectory() {
-  if constexpr (port::IsLinuxBase() || port::IsWasm()) {
+  if constexpr (port::IsLinuxBase() || port::IsWasm() || port::IsFreeBSD()) {
     return std::string(kMozcServerDir);
   }
 
@@ -369,7 +369,7 @@ std::string SystemUtil::GetDocumentDirectory() {
 }
 
 std::string SystemUtil::GetDocumentDirectory() {
-  if constexpr (port::IsLinuxBase()) {
+  if constexpr (port::IsLinuxBase() || port::IsFreeBSD()) {
     return std::string(kMozcDocumentDir);
   } else if constexpr (port::IsAppleBase()) {
     return GetServerDirectory();
@@ -562,9 +562,9 @@ std::string SystemUtil::GetDesktopNameAsString() {
 #endif  // _WIN32
 
 std::string SystemUtil::GetDesktopNameAsString() {
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__FreeBSD__)
   return Environ::GetEnv("DISPLAY");
-#endif  // __linux__ || __wasm__
+#endif  // __linux__ || __wasm__ || __FreeBSD__
 
 #if defined(__APPLE__)
   return "";
@@ -623,9 +623,11 @@ std::string SystemUtil::GetOSVersionString() {
                           AndroidUtil::kSystemPropertyOsVersion, "Unknown"));
 #elif defined(__linux__)
   return "Linux";
-#else   // !_WIN32 && !__APPLE__ && !__linux__
+#elif defined(__FreeBSD__)
+  return "FreeBSD";
+#else   // !_WIN32 && !__APPLE__ && !__linux__ && !__FreeBSD__
   return "Unknown";
-#endif  // _WIN32, __APPLE__, __linux__
+#endif  // _WIN32, __APPLE__, __linux__, __FreeBSD__
 }
 
 void SystemUtil::DisableIME() {
@@ -660,7 +662,7 @@ uint64_t SystemUtil::GetTotalPhysicalMemory() {
   return total_memory;
 #endif  // __APPLE__
 
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__FreeBSD__)
 #if defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
   const int32_t page_size = sysconf(_SC_PAGESIZE);
   const int32_t number_of_phyisical_pages = sysconf(_SC_PHYS_PAGES);
@@ -673,7 +675,7 @@ uint64_t SystemUtil::GetTotalPhysicalMemory() {
 #else   // defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
   return 0;
 #endif  // defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
-#endif  // __linux__ || __wasm__
+#endif  // __linux__ || __wasm__ || __FreeBSD__
 
   // If none of the above platforms is specified, the compiler raises an error
   // because of no return value.
