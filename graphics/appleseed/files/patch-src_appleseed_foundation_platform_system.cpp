--- src/appleseed/foundation/platform/system.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed/foundation/platform/system.cpp
@@ -548,6 +548,13 @@ namespace
             "=d" (regs[edx]));
     }
 
+    uint64 xgetbv(const int32 index)
+    {
+        uint32 eax, edx;
+        __asm__ __volatile__("xgetbv" : "=a"(eax), "=d"(edx) : "c"(index));
+        return (static_cast<uint64>(edx) << 32) | eax;
+    }
+
 #define BIT(n)              (1UL << (n))
 #define BITMASK(h, l)       ((BIT(h) | (BIT(h) - 1)) & ~(BIT(l) - 1))
 #define BITFIELD(x, h, l)   (((x) & BITMASK(h, l)) >> l)
@@ -1077,7 +1084,8 @@ namespace
         // Reference: http://stackoverflow.com/a/22521619/922184
 
         uint32 cpuinfo[4];
-        cpuid(cpuinfo, 1);
+        cpuinfo[0] = 1;
+        cpuid(cpuinfo);
 
         const bool os_uses_xsave_xrstor = (cpuinfo[2] & (1UL << 27)) != 0;
         const bool cpu_avx_support = (cpuinfo[2] & (1UL << 28)) != 0;
@@ -1105,7 +1113,8 @@ namespace
         char vendor[13];
 
         uint32 cpuinfo[4];
-        cpuid(cpuinfo, 0);
+        cpuinfo[0] = 0;
+        cpuid(cpuinfo);
 
         memcpy(vendor + 0, &cpuinfo[1], 4);
         memcpy(vendor + 4, &cpuinfo[3], 4);
@@ -1134,13 +1143,15 @@ void System::detect_x86_cpu_features(X86CPUFeatures& f
 
     // EAX=0: Get vendor ID.
     uint32 cpuinfo[4];
-    cpuid(cpuinfo, 0x00000000);
+    cpuinfo[0] = 0;
+    cpuid(cpuinfo);
     const uint32 highest_function_id = cpuinfo[0];
 
     if (highest_function_id >= 0x00000001)
     {
         // EAX=1: Processor Info and Feature Bits.
-        cpuid(cpuinfo, 0x00000001);
+        cpuinfo[0] = 1;
+        cpuid(cpuinfo);
         features.m_hw_mmx           = (cpuinfo[3] & (1UL << 23)) != 0;
         features.m_hw_sse           = (cpuinfo[3] & (1UL << 25)) != 0;
         features.m_hw_sse2          = (cpuinfo[3] & (1UL << 26)) != 0;
@@ -1158,7 +1169,8 @@ void System::detect_x86_cpu_features(X86CPUFeatures& f
     if (highest_function_id >= 0x00000007)
     {
         // EAX=7: Extended Features.
-        cpuid(cpuinfo, 0x00000007);
+        cpuinfo[0] = 7;
+        cpuid(cpuinfo);
         features.m_hw_avx2          = (cpuinfo[1] & (1UL <<  5)) != 0;
         features.m_hw_bmi1          = (cpuinfo[1] & (1UL <<  3)) != 0;
         features.m_hw_bmi2          = (cpuinfo[1] & (1UL <<  8)) != 0;
@@ -1178,13 +1190,15 @@ void System::detect_x86_cpu_features(X86CPUFeatures& f
     }
 
     // EAX=0x80000000: Get Highest Extended Function Supported.
-    cpuid(cpuinfo, 0x80000000);
+    cpuinfo[0] = 0x80000000;
+    cpuid(cpuinfo);
     const uint32 highest_ext_function_id = cpuinfo[0];
 
     if (highest_ext_function_id >= 0x80000001)
     {
         // EAX=0x80000001: Extended Processor Info and Feature Bits.
-        cpuid(cpuinfo, 0x80000001);
+        cpuinfo[0] = 0x80000001;
+        cpuid(cpuinfo);
         features.m_hw_x64           = (cpuinfo[3] & (1UL << 29)) != 0;
         features.m_hw_abm           = (cpuinfo[2] & (1UL <<  5)) != 0;
         features.m_hw_sse4a         = (cpuinfo[2] & (1UL <<  6)) != 0;
