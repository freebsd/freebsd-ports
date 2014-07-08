--- ./asmrun/arm.S.orig	2014-04-28 13:10:19.000000000 +0100
+++ ./asmrun/arm.S	2014-04-28 13:10:42.000000000 +0100
@@ -44,6 +44,15 @@
         cmp     \reg, #0
         beq     \lbl
         .endm
+#elif defined(SYS_freebsd)
+        .arch   armv6
+        .arm
+
+    /* Compatibility macros */
+        .macro  cbz reg, lbl
+        cmp     \reg, #0
+        beq     \lbl
+        .endm
 #endif
 
 trap_ptr        .req    r8
