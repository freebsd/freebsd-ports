--- src/hotspot/os_cpu/bsd_aarch64/vm_version_bsd_aarch64.cpp
+++ src/hotspot/os_cpu/bsd_aarch64/vm_version_bsd_aarch64.cpp
@@ -25,10 +25,10 @@
 
 #include "precompiled.hpp"
 #include "runtime/os.hpp"
-#include "runtime/vm_version.hpp"
+#include "vm_version_aarch64.hpp"
 
-#if defined (__FreeBSD__)
 #include <machine/armreg.h>
+#if defined (__FreeBSD__)
 #include <machine/elf.h>
 #endif
 
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
@@ -186,6 +202,17 @@ const struct cpu_implementers cpu_implementers[] = {
 	CPU_IMPLEMENTER_NONE,
 };
 
+#ifdef __OpenBSD__
+// READ_SPECIALREG is not available from userland on OpenBSD.
+// Hardcode these values to the "lowest common denominator"
+unsigned long VM_Version::os_get_processor_features() {
+  _cpu = CPU_IMPL_ARM;
+  _model = CPU_PART_CORTEX_A53;
+  _variant = 0;
+  _revision = 0;
+  return HWCAP_ASIMD;
+}
+#else
 unsigned long VM_Version::os_get_processor_features() {
   struct cpu_desc cpu_desc[1];
   struct cpu_desc user_cpu_desc;
@@ -229,26 +256,26 @@ unsigned long VM_Version::os_get_processor_features() {
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
 
@@ -259,3 +286,4 @@ unsigned long VM_Version::os_get_processor_features() {
 
   return auxv;
 }
+#endif
