--- src/hotspot/os_cpu/bsd_aarch64/vm_version_bsd_aarch64.cpp
+++ src/hotspot/os_cpu/bsd_aarch64/vm_version_bsd_aarch64.cpp
@@ -76,6 +76,22 @@
 #define ID_AA64PFR0_AdvSIMD_HP (UL(0x1) << ID_AA64PFR0_AdvSIMD_SHIFT)
 #endif
 
+#ifndef ID_AA64ISAR0_AES_VAL
+#define ID_AA64ISAR0_AES_VAL ID_AA64ISAR0_AES
+#endif
+
+#ifndef ID_AA64ISAR0_SHA1_VAL
+#define ID_AA64ISAR0_SHA1_VAL ID_AA64ISAR0_SHA1
+#endif
+
+#ifndef ID_AA64ISAR0_SHA2_VAL
+#define ID_AA64ISAR0_SHA2_VAL ID_AA64ISAR0_SHA2
+#endif
+
+#ifndef ID_AA64ISAR0_CRC32_VAL
+#define ID_AA64ISAR0_CRC32_VAL ID_AA64ISAR0_CRC32
+#endif
+
 #define	CPU_IMPL_ARM		0x41
 #define	CPU_IMPL_BROADCOM	0x42
 #define	CPU_IMPL_CAVIUM		0x43
@@ -240,26 +256,26 @@ unsigned long VM_Version::os_get_processor_features() {
   _model = cpu_desc[cpu].cpu_part_num;
   _revision = cpu_desc[cpu].cpu_revision;
 
-  id_aa64isar0 = READ_SPECIALREG(ID_AA64ISAR0_EL1);
-  id_aa64pfr0 = READ_SPECIALREG(ID_AA64PFR0_EL1);
+  id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+  id_aa64pfr0 = READ_SPECIALREG(id_aa64pfr0_el1);
 
-  if (ID_AA64ISAR0_AES(id_aa64isar0) == ID_AA64ISAR0_AES_BASE) {
+  if (ID_AA64ISAR0_AES_VAL(id_aa64isar0) == ID_AA64ISAR0_AES_BASE) {
     auxv = auxv | HWCAP_AES;
   }
 
-  if (ID_AA64ISAR0_AES(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL) {
+  if (ID_AA64ISAR0_AES_VAL(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL) {
     auxv = auxv | HWCAP_PMULL;
   }
 
-  if (ID_AA64ISAR0_SHA1(id_aa64isar0) == ID_AA64ISAR0_SHA1_BASE) {
+  if (ID_AA64ISAR0_SHA1_VAL(id_aa64isar0) == ID_AA64ISAR0_SHA1_BASE) {
     auxv = auxv | HWCAP_SHA1;
   }
 
-  if (ID_AA64ISAR0_SHA2(id_aa64isar0) == ID_AA64ISAR0_SHA2_BASE) {
+  if (ID_AA64ISAR0_SHA2_VAL(id_aa64isar0) == ID_AA64ISAR0_SHA2_BASE) {
     auxv = auxv | HWCAP_SHA2;
   }
 
-  if (ID_AA64ISAR0_CRC32(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE) {
+  if (ID_AA64ISAR0_CRC32_VAL(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE) {
     auxv = auxv | HWCAP_CRC32;
   }
 
