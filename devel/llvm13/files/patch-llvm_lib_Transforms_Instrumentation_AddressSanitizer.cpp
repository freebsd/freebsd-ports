--- llvm/lib/Transforms/Instrumentation/AddressSanitizer.cpp.orig	2021-06-28 16:23:38 UTC
+++ llvm/lib/Transforms/Instrumentation/AddressSanitizer.cpp
@@ -108,6 +108,7 @@ static const uint64_t kAArch64_ShadowOffset64 = 1ULL <
 static const uint64_t kRISCV64_ShadowOffset64 = 0x20000000;
 static const uint64_t kFreeBSD_ShadowOffset32 = 1ULL << 30;
 static const uint64_t kFreeBSD_ShadowOffset64 = 1ULL << 46;
+static const uint64_t kFreeBSDKasan_ShadowOffset64 = 0xdffff7c000000000;
 static const uint64_t kNetBSD_ShadowOffset32 = 1ULL << 30;
 static const uint64_t kNetBSD_ShadowOffset64 = 1ULL << 46;
 static const uint64_t kNetBSDKasan_ShadowOffset64 = 0xdfff900000000000;
@@ -484,9 +485,12 @@ static ShadowMapping getShadowMapping(Triple &TargetTr
       Mapping.Offset = kPPC64_ShadowOffset64;
     else if (IsSystemZ)
       Mapping.Offset = kSystemZ_ShadowOffset64;
-    else if (IsFreeBSD && !IsMIPS64)
-      Mapping.Offset = kFreeBSD_ShadowOffset64;
-    else if (IsNetBSD) {
+    else if (IsFreeBSD && !IsMIPS64) {
+      if (IsKasan)
+        Mapping.Offset = kFreeBSDKasan_ShadowOffset64;
+      else
+        Mapping.Offset = kFreeBSD_ShadowOffset64;
+    } else if (IsNetBSD) {
       if (IsKasan)
         Mapping.Offset = kNetBSDKasan_ShadowOffset64;
       else
