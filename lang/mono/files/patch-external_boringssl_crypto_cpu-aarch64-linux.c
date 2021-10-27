--- external/boringssl/crypto/cpu-aarch64-linux.c.orig	2018-08-24 17:17:16 UTC
+++ external/boringssl/crypto/cpu-aarch64-linux.c
@@ -25,7 +25,32 @@
 
 extern uint32_t OPENSSL_armcap_P;
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <machine/armreg.h>
+
 void OPENSSL_cpuid_setup(void) {
+  uint64_t id_aa64isar0;
+
+  id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+
+  OPENSSL_armcap_P |= ARMV7_NEON;
+
+  if (ID_AA64ISAR0_AES_VAL(id_aa64isar0) == ID_AA64ISAR0_AES_BASE) {
+    OPENSSL_armcap_P |= ARMV8_AES;
+  }
+  if (ID_AA64ISAR0_AES_VAL(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL) {
+    OPENSSL_armcap_P |= ARMV8_PMULL;
+  }
+  if (ID_AA64ISAR0_SHA1_VAL(id_aa64isar0) == ID_AA64ISAR0_SHA1_BASE) {
+    OPENSSL_armcap_P |= ARMV8_SHA1;
+  }
+  if(ID_AA64ISAR0_SHA2_VAL(id_aa64isar0) == ID_AA64ISAR0_SHA2_BASE) {
+    OPENSSL_armcap_P |= ARMV8_SHA256;
+  }
+}
+#else // linux
+void OPENSSL_cpuid_setup(void) {
   unsigned long hwcap = getauxval(AT_HWCAP);
 
   /* See /usr/include/asm/hwcap.h on an aarch64 installation for the source of
@@ -57,5 +82,6 @@ void OPENSSL_cpuid_setup(void) {
     OPENSSL_armcap_P |= ARMV8_SHA256;
   }
 }
+#endif
 
 #endif /* OPENSSL_AARCH64 && !OPENSSL_STATIC_ARMCAP */
