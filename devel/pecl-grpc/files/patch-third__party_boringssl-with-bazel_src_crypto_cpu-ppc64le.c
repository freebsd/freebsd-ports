--- third_party/boringssl-with-bazel/src/crypto/cpu-ppc64le.c.orig	2020-10-26 11:38:52 UTC
+++ third_party/boringssl-with-bazel/src/crypto/cpu-ppc64le.c
@@ -28,7 +28,11 @@
 #endif
 
 void OPENSSL_cpuid_setup(void) {
+#if defined(__linux__)
   OPENSSL_ppc64le_hwcap2 = getauxval(AT_HWCAP2);
+#elif defined(__FreeBSD__)
+  elf_aux_info(AT_HWCAP2, &OPENSSL_ppc64le_hwcap2, sizeof(OPENSSL_ppc64le_hwcap2));
+#endif
 }
 
 int CRYPTO_is_PPC64LE_vcrypto_capable(void) {
