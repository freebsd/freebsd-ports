--- crc.cpp.orig	2026-07-13 15:17:43 UTC
+++ crc.cpp
@@ -48,6 +48,10 @@ void InitCRC32(uint *CRCTab)
     size_t Size=sizeof(Value);
     int RetCode=sysctlbyname("hw.optional.armv8_crc32",&Value,&Size,NULL,0);
     CRC_Neon=RetCode==0 && Value!=0;
+  #elif defined(__FreeBSD__) || defined(__OpenBSD__)
+    unsigned long Value;
+    int RetCode=elf_aux_info(AT_HWCAP, &Value, sizeof(Value));
+    CRC_Neon=RetCode==0 && (Value & HWCAP_CRC32)!=0;
   #else
     CRC_Neon=(getauxval(AT_HWCAP) & HWCAP_CRC32)!=0;
   #endif
