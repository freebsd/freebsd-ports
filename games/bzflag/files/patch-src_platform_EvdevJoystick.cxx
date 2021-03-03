--- src/platform/EvdevJoystick.cxx.orig	2021-03-02 20:03:56 UTC
+++ src/platform/EvdevJoystick.cxx
@@ -36,7 +36,7 @@
 
 static inline int test_bit (int nr, const volatile void *addr)
 {
-    return 1 & (((const volatile __u32 *) addr)[nr >> 5] >> (nr & 31));
+    return 1 & (((const volatile uint32_t *) addr)[nr >> 5] >> (nr & 31));
 }
 
 bool         EvdevJoystick::isEvdevAvailable()
