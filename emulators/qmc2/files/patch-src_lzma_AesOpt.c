--- src/lzma/AesOpt.c.orig	2022-04-29 08:33:05 UTC
+++ src/lzma/AesOpt.c
@@ -506,7 +506,7 @@ VAES_COMPAT_STUB (AesCtr_Code_HW)
 #endif // ! USE_INTEL_VAES
 
 
-#elif defined(MY_CPU_ARM_OR_ARM64) && defined(MY_CPU_LE)
+#elif defined(MY_CPU_ARM64) && defined(MY_CPU_LE)
 
   #if defined(__clang__)
     #if (__clang_major__ >= 8) // fix that check
@@ -773,4 +773,25 @@ AES_FUNC_START2 (AesCtr_Code_HW)
 
 #endif // USE_HW_AES
 
-#endif // MY_CPU_ARM_OR_ARM64
+#else
+
+/* no USE_HW_AES */
+
+#pragma message("AES  HW_SW stub was used")
+
+#define AES_TYPE_keys UInt32
+#define AES_TYPE_data Byte
+
+#define AES_FUNC_START(name) \
+    void MY_FAST_CALL name(UInt32 *p, Byte *data, size_t numBlocks) \
+
+#define AES_COMPAT_STUB(name) \
+    AES_FUNC_START(name); \
+    AES_FUNC_START(name ## _HW) \
+    { name(p, data, numBlocks); }
+
+AES_COMPAT_STUB (AesCbc_Encode)
+AES_COMPAT_STUB (AesCbc_Decode)
+AES_COMPAT_STUB (AesCtr_Code)
+
+#endif
