--- src/base/process.cc.orig	2026-10-18 06:50:24 UTC
+++ src/base/process.cc
@@ -100,7 +100,7 @@ bool Process::OpenBrowser(absl::string_view url) {
       L"open", win32::Utf8ToWide(url).c_str(), nullptr);
 #endif  // _WIN32
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 #ifndef MOZC_BROWSER_COMMAND
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
@@ -109,7 +109,7 @@ bool Process::OpenBrowser(absl::string_view url) {
 #endif  // MOZC_BROWSER_COMMAND
 
   return SpawnProcess(MOZC_BROWSER_COMMAND, url);
-#endif  // __linux__
+#endif  // __linux__ || __FreeBSD__
 
 #ifdef __APPLE__
   return MacProcess::OpenBrowserForMac(url);
@@ -189,7 +189,7 @@ bool Process::SpawnProcess(absl::string_view path, abs
   }
 #endif  // __APPLE__
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
   // Do not call posix_spawn() for obviously bad path.
   if (!S_ISREG(statbuf.st_mode)) {
     LOG(ERROR) << "Not a regular file: " << path;
@@ -205,7 +205,9 @@ bool Process::SpawnProcess(absl::string_view path, abs
     LOG(ERROR) << "Can't execute setuid or setgid binaries: " << path;
     return false;
   }
+#endif	// __linux__ || __FreeBSD__
 
+#ifdef __linux__
   // Use simple heap corruption checker in child processes. This setenv() does
   // not affect current process behavior since Glibc never check the variable
   // after main().
@@ -389,7 +391,7 @@ bool Process::LaunchErrorMessageDialog(absl::string_vi
   }
 #endif  // _WIN32
 
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) && !defined(__ANDROID__)) || defined(__FreeBSD__)
   constexpr char kMozcTool[] = "mozc_tool";
   const std::string arg =
       absl::StrCat("--mode=error_message_dialog --error_type=", error_type);
@@ -398,7 +400,7 @@ bool Process::LaunchErrorMessageDialog(absl::string_vi
     LOG(ERROR) << "cannot launch " << kMozcTool;
     return false;
   }
-#endif  // __linux__ && !__ANDROID__
+#endif  // (__linux__ && !__ANDROID__) || __FreeBSD__
 
   return true;
 }
