--- sandbox/policy/sandbox_type.cc.orig	2026-04-28 21:06:17 UTC
+++ sandbox/policy/sandbox_type.cc
@@ -13,7 +13,7 @@
 #include "sandbox/policy/mojom/sandbox.mojom.h"
 #include "sandbox/policy/switches.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/gpu/buildflags.h"  // nogncheck
 #include "media/media_buildflags.h"  // nogncheck
 #endif
@@ -35,7 +35,7 @@ constexpr char kSpeechRecognitionSandbox[] = "speech_r
 constexpr char kSpeechRecognitionSandbox[] = "speech_recognition";
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 constexpr char kPrintBackendSandbox[] = "print_backend";
 constexpr char kScreenAISandbox[] = "screen_ai";
 #endif
@@ -56,11 +56,11 @@ constexpr char kProxyResolverSandbox[] = "proxy_resolv
 constexpr char kProxyResolverSandbox[] = "proxy_resolver";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 constexpr char kVideoCaptureSandbox[] = "video_capture";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kShapeDetectionSandbox[] = "shape_detection";
 // USE_LINUX_VIDEO_ACCELERATION implies IS_LINUX || IS_CHROMEOS, so this double
 // #if is redundant, however, we cannot include "media/gpu/buildflags.h" on all
@@ -78,7 +78,7 @@ constexpr char kNearbySandbox[] = "nearby";
 constexpr char kNearbySandbox[] = "nearby";
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kOnDeviceTranslationSandbox[] = "on_device_translation";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
 
@@ -128,7 +128,7 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
     case Sandbox::kCdm:
     case Sandbox::kPrintCompositor:
     case Sandbox::kAudio:
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -138,7 +138,7 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
     case Sandbox::kIconReader:
     case Sandbox::kMediaFoundationCdm:
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kShapeDetection:
 #if BUILDFLAG(USE_LINUX_VIDEO_ACCELERATION)
     case Sandbox::kHardwareVideoDecoding:
@@ -157,12 +157,12 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
     case Sandbox::kProxyResolver:
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case Sandbox::kPrintBackend:
     case Sandbox::kScreenAI:
 #endif
     case Sandbox::kSpeechRecognition:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kOnDeviceTranslation:
 #endif
       DCHECK(command_line->GetSwitchValueASCII(switches::kProcessType) ==
@@ -172,7 +172,7 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
           switches::kServiceSandboxType,
           StringFromUtilitySandboxType(sandbox_type));
       return;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
       return;
 #endif
@@ -203,7 +203,7 @@ sandbox::mojom::Sandbox SandboxTypeFromCommandLine(
     return Sandbox::kGpu;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Intermediate process gains a sandbox later.
   if (process_type == switches::kZygoteProcessType)
     return Sandbox::kZygoteIntermediateSandbox;
@@ -242,7 +242,7 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
       return kUtilitySandbox;
     case Sandbox::kAudio:
       return kAudioSandbox;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return kVideoCaptureSandbox;
 #endif
@@ -253,13 +253,13 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
     case Sandbox::kSpeechRecognition:
       return kSpeechRecognitionSandbox;
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case Sandbox::kPrintBackend:
       return kPrintBackendSandbox;
     case Sandbox::kScreenAI:
       return kScreenAISandbox;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kOnDeviceTranslation:
       return kOnDeviceTranslationSandbox;
 #endif
@@ -281,7 +281,7 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
     case Sandbox::kProxyResolver:
       return kProxyResolverSandbox;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kShapeDetection:
       return kShapeDetectionSandbox;
 #if BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
@@ -304,7 +304,7 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
       // The following are not utility processes so should not occur.
     case Sandbox::kRenderer:
     case Sandbox::kGpu:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
 #endif
       NOTREACHED();
@@ -380,7 +380,7 @@ sandbox::mojom::Sandbox UtilitySandboxTypeFromString(
     return Sandbox::kSpeechRecognition;
   }
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kPrintBackendSandbox) {
     return Sandbox::kPrintBackend;
   }
@@ -388,17 +388,17 @@ sandbox::mojom::Sandbox UtilitySandboxTypeFromString(
     return Sandbox::kScreenAI;
   }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kOnDeviceTranslationSandbox) {
     return Sandbox::kOnDeviceTranslation;
   }
 #endif
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kVideoCaptureSandbox) {
     return Sandbox::kVideoCapture;
   }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kShapeDetectionSandbox) {
     return Sandbox::kShapeDetection;
   }
