--- third_party/unrar/src/crc.cpp.orig	2025-02-21 07:45:09 UTC
+++ third_party/unrar/src/crc.cpp
@@ -43,12 +43,18 @@ void InitCRC32(uint *CRCTab)
   }
 
 #ifdef USE_NEON_CRC32
-  #ifdef _APPLE
+  #if defined(_APPLE)
     // getauxval isn't available in OS X
     uint Value=0;
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
