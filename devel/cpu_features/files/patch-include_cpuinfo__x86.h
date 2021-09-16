--- include/cpuinfo_x86.h.orig	2021-09-16 15:51:24 UTC
+++ include/cpuinfo_x86.h
@@ -137,6 +137,7 @@ typedef enum {
   AMD_BULLDOZER,   // K15
   AMD_JAGUAR,      // K16
   AMD_ZEN,         // K17
+  AMD_ZEN3,        // K19
 } X86Microarchitecture;
 
 // Returns the underlying microarchitecture by looking at X86Info's vendor,
