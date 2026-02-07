--- src/appleseed/foundation/platform/system.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed/foundation/platform/system.cpp
@@ -548,6 +548,20 @@ namespace
             "=d" (regs[edx]));
     }
 
+    // Two-argument compatibility method.
+    void cpuid(uint32 cpuinfo[4], const uint32 index)
+    {
+        cpuinfo[eax] = index;
+        cpuid(cpuinfo);
+    }
+
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
