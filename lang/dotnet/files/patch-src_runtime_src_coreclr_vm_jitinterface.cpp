--- src/runtime/src/coreclr/vm/jitinterface.cpp.orig	2024-01-30 14:43:23.896193000 +0000
+++ src/runtime/src/coreclr/vm/jitinterface.cpp	2024-01-30 14:44:17.447492000 +0000
@@ -1597,6 +1597,10 @@
                 optimizeThreadStaticAccess = GetTlsIndexObjectAddress() != nullptr;
 #endif // !TARGET_OSX && TARGET_UNIX && TARGET_AMD64
 
+#if defined(TARGET_ARM64) && defined(TARGET_FREEBSD)
+		optimizeThreadStaticAccess = false;
+#endif
+
                 if (optimizeThreadStaticAccess)
                 {
                     // For windows x64/x86/arm64, linux x64/arm64/loongarch64/riscv64:
