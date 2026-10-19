--- src/client/client.cc.orig	2026-10-18 06:52:10 UTC
+++ src/client/client.cc
@@ -884,7 +884,7 @@ bool Client::LaunchTool(absl::string_view mode,
     return false;
   }
 
-#if defined(_WIN32) || defined(__linux__)
+#if defined(_WIN32) || defined(__linux__) || defined(__FreeBSD__)
   std::string arg = absl::StrCat("--mode=", mode);
   if (!extra_arg.empty()) {
     absl::StrAppend(&arg, " ", extra_arg);
@@ -893,7 +893,7 @@ bool Client::LaunchTool(absl::string_view mode,
     LOG(ERROR) << "Cannot execute: " << kMozcTool << " " << arg;
     return false;
   }
-#endif  // _WIN32 || __linux__
+#endif  // _WIN32 || __linux__ || __FreeBSD__
 
   // TODO(taku): move MacProcess inside SpawnMozcProcess.
   // TODO(taku): support extra_arg.
