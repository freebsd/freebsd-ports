https://github.com/citra-emu/citra/issues/3796

--- externals/cryptopp/cryptopp/cpu.h.orig	2018-02-22 14:26:16 UTC
+++ externals/cryptopp/cryptopp/cpu.h
@@ -614,7 +614,12 @@ inline int GetCacheLineSize()
 	#define GNU_AS2(x, y) #x ", " #y ";" NEW_LINE
 	#define GNU_AS3(x, y, z) #x ", " #y ", " #z ";" NEW_LINE
 	#define GNU_ASL(x) "\n" #x ":" NEW_LINE
+// clang 5.0.0 and apple clang 9.0.0 don't support numerical backward jumps
+#if (CRYPTOPP_LLVM_CLANG_VERSION >= 50000) || (CRYPTOPP_APPLE_CLANG_VERSION >= 90000)
+	#define GNU_ASJ(x, y, z) ATT_PREFIX ";" NEW_LINE #x " " #y #z ";" NEW_LINE INTEL_PREFIX ";" NEW_LINE
+#else
 	#define GNU_ASJ(x, y, z) #x " " #y #z ";" NEW_LINE
+#endif
 	#define AS1(x) GNU_AS1(x)
 	#define AS2(x, y) GNU_AS2(x, y)
 	#define AS3(x, y, z) GNU_AS3(x, y, z)
