--- adb/client/adb_install.cpp.orig	2019-10-18 00:22:21 UTC
+++ adb/client/adb_install.cpp
@@ -35,9 +35,11 @@
 #include "adb_utils.h"
 #include "client/file_sync_client.h"
 #include "commandline.h"
+#if defined(ENABLE_FASTDEPLOY)
 #include "fastdeploy.h"
 
 static constexpr int kFastDeployMinApi = 24;
+#endif
 
 namespace {
 
@@ -167,6 +169,7 @@ static int install_app_streamed(int argc, const char**
     }
 
     if (use_fastdeploy) {
+#if defined(ENABLE_FASTDEPLOY)
         auto metadata = extract_metadata(file);
         if (metadata.has_value()) {
             // pass all but 1st (command) and last (apk path) parameters through to pm for
@@ -175,6 +178,9 @@ static int install_app_streamed(int argc, const char**
             auto patchFd = install_patch(pm_args.size(), pm_args.data());
             return stream_patch(file, std::move(metadata.value()), std::move(patchFd));
         }
+#else
+        error_exit("fastdeploy is disabled");
+#endif
     }
 
     struct stat sb;
@@ -189,7 +195,7 @@ static int install_app_streamed(int argc, const char**
         return 1;
     }
 
-#ifdef __linux__
+#if !defined(__APPLE__) && !defined(_WIN32)
     posix_fadvise(local_fd.get(), 0, 0, POSIX_FADV_SEQUENTIAL | POSIX_FADV_NOREUSE);
 #endif
 
@@ -263,6 +269,7 @@ static int install_app_legacy(int argc, const char** a
     argv[last_apk] = apk_dest.c_str(); /* destination name, not source location */
 
     if (use_fastdeploy) {
+#if defined(ENABLE_FASTDEPLOY)
         auto metadata = extract_metadata(apk_file[0]);
         if (metadata.has_value()) {
             auto patchFd = apply_patch_on_device(apk_dest.c_str());
@@ -273,6 +280,9 @@ static int install_app_legacy(int argc, const char** a
 
             return status;
         }
+#else
+        error_exit("fastdeploy is disabled");
+#endif
     }
 
     if (do_sync_push(apk_file, apk_dest.c_str(), false)) {
@@ -288,7 +298,9 @@ int install_app(int argc, const char** argv) {
     InstallMode installMode = INSTALL_DEFAULT;
     bool use_fastdeploy = false;
     bool is_reinstall = false;
+#if defined(ENABLE_FASTDEPLOY)
     FastDeploy_AgentUpdateStrategy agent_update_strategy = FastDeploy_AgentUpdateDifferentVersion;
+#endif
 
     for (int i = 1; i < argc; i++) {
         if (!strcmp(argv[i], "--streaming")) {
@@ -309,13 +321,19 @@ int install_app(int argc, const char** argv) {
             use_fastdeploy = false;
         } else if (!strcmp(argv[i], "--force-agent")) {
             processedArgIndicies.push_back(i);
+#if defined(ENABLE_FASTDEPLOY)
             agent_update_strategy = FastDeploy_AgentUpdateAlways;
+#endif
         } else if (!strcmp(argv[i], "--date-check-agent")) {
             processedArgIndicies.push_back(i);
+#if defined(ENABLE_FASTDEPLOY)
             agent_update_strategy = FastDeploy_AgentUpdateNewerTimeStamp;
+#endif
         } else if (!strcmp(argv[i], "--version-check-agent")) {
             processedArgIndicies.push_back(i);
+#if defined(ENABLE_FASTDEPLOY)
             agent_update_strategy = FastDeploy_AgentUpdateDifferentVersion;
+#endif
         }
     }
 
@@ -327,6 +345,7 @@ int install_app(int argc, const char** argv) {
         error_exit("Attempting to use streaming install on unsupported device");
     }
 
+#if defined(ENABLE_FASTDEPLOY)
     if (use_fastdeploy && get_device_api_level() < kFastDeployMinApi) {
         printf("Fast Deploy is only compatible with devices of API version %d or higher, "
                "ignoring.\n",
@@ -334,6 +353,7 @@ int install_app(int argc, const char** argv) {
         use_fastdeploy = false;
     }
     fastdeploy_set_agent_update_strategy(agent_update_strategy);
+#endif
 
     std::vector<const char*> passthrough_argv;
     for (int i = 0; i < argc; i++) {
