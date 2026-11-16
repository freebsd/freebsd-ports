--- crc.cpp.orig	2026-10-27 08:48:32 UTC
+++ crc.cpp
@@ -50,6 +50,12 @@ void InitCRC32(uint *CRCTab)
     size_t Size=sizeof(Value);
     int RetCode=sysctlbyname("hw.optional.armv8_crc32",&Value,&Size,NULL,0);
     CRC_Neon=RetCode==0 && Value!=0;
+  #elif defined(__FreeBSD__)
+    // getauxval isn't available on FreeBSD
+    uint64 Reg=READ_SPECIALREG(id_aa64isar0_el1);
+    if (ID_AA64ISAR0_CRC32_VAL(Reg) == ID_AA64ISAR0_CRC32_BASE) {
+      CRC_Neon=true;
+    }
   #else
     CRC_Neon=(getauxval(AT_HWCAP) & HWCAP_CRC32)!=0;
   #endif
