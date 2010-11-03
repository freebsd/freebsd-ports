--- src/recompiler/target-i386/cpu.h.orig	2010-07-15 20:13:56.000000000 +0200
+++ src/recompiler/target-i386/cpu.h	2010-11-01 12:23:16.000000000 +0100
@@ -678,7 +678,7 @@
        user */
     struct APICState *apic_state;
 #else
-    uint32_t alignment2[3];
+    uint32_t alignment2[2];
     /** Profiling tb_flush. */
     STAMPROFILE StatTbFlush;
 #endif
