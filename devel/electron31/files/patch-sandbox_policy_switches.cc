--- sandbox/policy/switches.cc.orig	2023-11-29 21:40:08 UTC
+++ sandbox/policy/switches.cc
@@ -54,10 +54,10 @@ const char kMirroringSandbox[] = "mirroring";
 const char kMirroringSandbox[] = "mirroring";
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 const char kHardwareVideoDecodingSandbox[] = "hardware_video_decoding";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kHardwareVideoEncodingSandbox[] = "hardware_video_encoding";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -96,7 +96,9 @@ const char kNoSandbox[] = "no-sandbox";
 // Meant to be used as a browser-level switch for testing purposes only.
 const char kNoSandbox[] = "no-sandbox";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+const char kDisableUnveil[] = "disable-unveil";
+
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Instructs the zygote to launch without a sandbox. Processes forked from this
 // type of zygote will apply their own custom sandboxes later.
 const char kNoZygoteSandbox[] = "no-zygote-sandbox";
