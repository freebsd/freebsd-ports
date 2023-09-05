--- C/AesOpt.c.orig	2023-09-05 00:20:25 UTC
+++ C/AesOpt.c
@@ -554,7 +554,7 @@ VAES_COMPAT_STUB (AesCtr_Code_HW)
 #endif // ! USE_INTEL_VAES
 
 
-#elif defined(MY_CPU_ARM_OR_ARM64) && defined(MY_CPU_LE)
+#elif defined(MY_CPU_ARM64) && defined(MY_CPU_LE)
 
   #if defined(__clang__)
     #if (__clang_major__ >= 8) // fix that check
@@ -828,7 +828,28 @@ AES_FUNC_START2 (AesCtr_Code_HW)
 
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
+    void name(UInt32 *p, Byte *data, size_t numBlocks) \
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
 
 #undef NUM_WAYS
 #undef WOP_M1
