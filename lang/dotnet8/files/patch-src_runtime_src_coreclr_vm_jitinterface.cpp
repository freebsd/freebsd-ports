--- src/runtime/src/coreclr/vm/jitinterface.cpp.orig	2026-10-29 18:33:34 UTC
+++ src/runtime/src/coreclr/vm/jitinterface.cpp
@@ -1623,6 +1623,10 @@ void CEEInfo::getFieldInfo (CORINFO_RESOLVED_TOKEN * p
                     optimizeThreadStaticAccess = false;
                 }
 
+#if defined(TARGET_ARM64) && defined(TARGET_FREEBSD)
+		optimizeThreadStaticAccess = false;
+#endif
+
                 if (optimizeThreadStaticAccess)
                 {
                     // For windows x64/x86/arm64, linux x64/arm64/loongarch64/riscv64:
