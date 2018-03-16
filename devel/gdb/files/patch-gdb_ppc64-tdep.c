--- gdb/ppc64-tdep.c.orig	2018-03-15 16:02:11.651610000 +0100
+++ gdb/ppc64-tdep.c	2018-03-15 16:10:27.958608000 +0100
@@ -30,24 +30,27 @@
    you can use -1 to make masks.  */
 
 #define insn_d(opcd, rts, ra, d)                \
+  static_cast<unsigned int>(                    \
   ((((opcd) & 0x3f) << 26)                      \
    | (((rts) & 0x1f) << 21)                     \
    | (((ra) & 0x1f) << 16)                      \
-   | ((d) & 0xffff))
+   | ((d) & 0xffff)))
 
 #define insn_ds(opcd, rts, ra, d, xo)           \
+  static_cast<unsigned int>(                    \
   ((((opcd) & 0x3f) << 26)                      \
    | (((rts) & 0x1f) << 21)                     \
    | (((ra) & 0x1f) << 16)                      \
    | ((d) & 0xfffc)                             \
-   | ((xo) & 0x3))
+   | ((xo) & 0x3)))
 
 #define insn_xfx(opcd, rts, spr, xo)            \
+  static_cast<unsigned int>(                    \
   ((((opcd) & 0x3f) << 26)                      \
    | (((rts) & 0x1f) << 21)                     \
    | (((spr) & 0x1f) << 16)                     \
    | (((spr) & 0x3e0) << 6)                     \
-   | (((xo) & 0x3ff) << 1))
+   | (((xo) & 0x3ff) << 1)))
 
 /* PLT_OFF is the TOC-relative offset of a 64-bit PowerPC PLT entry.
    Return the function's entry point.  */
@@ -86,7 +89,7 @@
     { insn_d (-1, -1, -1, 0), insn_d (15, 12, 2, 0), 0 },
 
     /* std r2, 40(r1) */
-    { -1, insn_ds (62, 2, 1, 40, 0), 0 },
+    { static_cast<unsigned int>(-1), insn_ds (62, 2, 1, 40, 0), 0 },
 
     /* ld r11, <any>(r12) */
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 11, 12, 0, 0), 0 },
@@ -107,7 +110,7 @@
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 11, 12, 0, 0), 1 },
 
     /* bctr */
-    { -1, 0x4e800420, 0 },
+    { static_cast<unsigned int>(-1), 0x4e800420, 0 },
 
     { 0, 0, 0 }
   };
@@ -122,13 +125,13 @@
 static struct ppc_insn_pattern ppc64_standard_linkage2[] =
   {
     /* std r2, 40(r1) <optional> */
-    { -1, insn_ds (62, 2, 1, 40, 0), 1 },
+    { static_cast<unsigned int>(-1), insn_ds (62, 2, 1, 40, 0), 1 },
 
     /* addis r12, r2, <any> */
     { insn_d (-1, -1, -1, 0), insn_d (15, 12, 2, 0), 0 },
 
     /* std r2, 40(r1) <optional> */
-    { -1, insn_ds (62, 2, 1, 40, 0), 1 },
+    { static_cast<unsigned int>(-1), insn_ds (62, 2, 1, 40, 0), 1 },
 
     /* ld r11, <any>(r12) */
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 11, 12, 0, 0), 0 },
@@ -140,10 +143,10 @@
     { insn_xfx (-1, -1, -1, -1), insn_xfx (31, 11, 9, 467), 0 },
 
     /* xor r11, r11, r11 <optional> */
-    { -1, 0x7d6b5a78, 1 },
+    { static_cast<unsigned int>(-1), 0x7d6b5a78, 1 },
 
     /* add r12, r12, r11 <optional> */
-    { -1, 0x7d8c5a14, 1 },
+    { static_cast<unsigned int>(-1), 0x7d8c5a14, 1 },
 
     /* ld r2, <any>(r12) */
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 2, 12, 0, 0), 0 },
@@ -152,10 +155,10 @@
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 11, 12, 0, 0), 1 },
 
     /* bctr <optional> */
-    { -1, 0x4e800420, 1 },
+    { static_cast<unsigned int>(-1), 0x4e800420, 1 },
 
     /* cmpldi r2, 0 <optional> */
-    { -1, 0x28220000, 1 },
+    { static_cast<unsigned int>(-1), 0x28220000, 1 },
 
     { 0, 0, 0 }
   };
@@ -165,7 +168,7 @@
 static struct ppc_insn_pattern ppc64_standard_linkage3[] =
   {
     /* std r2, 40(r1) <optional> */
-    { -1, insn_ds (62, 2, 1, 40, 0), 1 },
+    { static_cast<unsigned int>(-1), insn_ds (62, 2, 1, 40, 0), 1 },
 
     /* ld r11, <any>(r2) */
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 11, 2, 0, 0), 0 },
@@ -177,10 +180,10 @@
     { insn_xfx (-1, -1, -1, -1), insn_xfx (31, 11, 9, 467), 0 },
 
     /* xor r11, r11, r11 <optional> */
-    { -1, 0x7d6b5a78, 1 },
+    { static_cast<unsigned int>(-1), 0x7d6b5a78, 1 },
 
     /* add r2, r2, r11 <optional> */
-    { -1, 0x7c425a14, 1 },
+    { static_cast<unsigned int>(-1), 0x7c425a14, 1 },
 
     /* ld r11, <any>(r2) <optional> */
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 11, 2, 0, 0), 1 },
@@ -189,10 +192,10 @@
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 2, 2, 0, 0), 0 },
 
     /* bctr <optional> */
-    { -1, 0x4e800420, 1 },
+    { static_cast<unsigned int>(-1), 0x4e800420, 1 },
 
     /* cmpldi r2, 0 <optional> */
-    { -1, 0x28220000, 1 },
+    { static_cast<unsigned int>(-1), 0x28220000, 1 },
 
     { 0, 0, 0 }
   };
@@ -204,7 +207,7 @@
 static struct ppc_insn_pattern ppc64_standard_linkage4[] =
   {
     /* std r2, 40(r1) <optional> */
-    { -1, insn_ds (62, 2, 1, 40, 0), 1 },
+    { static_cast<unsigned int>(-1), insn_ds (62, 2, 1, 40, 0), 1 },
 
     /* addis r11, r2, <any> */
     { insn_d (-1, -1, -1, 0), insn_d (15, 11, 2, 0), 0 },
@@ -219,10 +222,10 @@
     { insn_xfx (-1, -1, -1, -1), insn_xfx (31, 12, 9, 467), 0 },
 
     /* xor r2, r12, r12 <optional> */
-    { -1, 0x7d826278, 1 },
+    { static_cast<unsigned int>(-1), 0x7d826278, 1 },
 
     /* add r11, r11, r2 <optional> */
-    { -1, 0x7d6b1214, 1 },
+    { static_cast<unsigned int>(-1), 0x7d6b1214, 1 },
 
     /* ld r2, <any>(r11) */
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 2, 11, 0, 0), 0 },
@@ -231,10 +234,10 @@
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 11, 11, 0, 0), 1 },
 
     /* bctr <optional> */
-    { -1, 0x4e800420, 1 },
+    { static_cast<unsigned int>(-1), 0x4e800420, 1 },
 
     /* cmpldi r2, 0 <optional> */
-    { -1, 0x28220000, 1 },
+    { static_cast<unsigned int>(-1), 0x28220000, 1 },
 
     { 0, 0, 0 }
   };
@@ -246,7 +249,7 @@
 static struct ppc_insn_pattern ppc64_standard_linkage5[] =
   {
     /* std r2, 40(r1) <optional> */
-    { -1, insn_ds (62, 2, 1, 40, 0), 1 },
+    { static_cast<unsigned int>(-1), insn_ds (62, 2, 1, 40, 0), 1 },
 
     /* ld r12, <any>(r2) */
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 12, 2, 0, 0), 0 },
@@ -258,10 +261,10 @@
     { insn_xfx (-1, -1, -1, -1), insn_xfx (31, 12, 9, 467), 0 },
 
     /* xor r11, r12, r12 <optional> */
-    { -1, 0x7d8b6278, 1 },
+    { static_cast<unsigned int>(-1), 0x7d8b6278, 1 },
 
     /* add r2, r2, r11 <optional> */
-    { -1, 0x7c425a14, 1 },
+    { static_cast<unsigned int>(-1), 0x7c425a14, 1 },
 
     /* ld r11, <any>(r2) <optional> */
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 11, 2, 0, 0), 1 },
@@ -270,10 +273,10 @@
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 2, 2, 0, 0), 0 },
 
     /* bctr <optional> */
-    { -1, 0x4e800420, 1 },
+    { static_cast<unsigned int>(-1), 0x4e800420, 1 },
 
     /* cmpldi r2, 0 <optional> */
-    { -1, 0x28220000, 1 },
+    { static_cast<unsigned int>(-1), 0x28220000, 1 },
 
     { 0, 0, 0 }
   };
@@ -283,7 +286,7 @@
 static struct ppc_insn_pattern ppc64_standard_linkage6[] =
   {
     /* std r2, 24(r1) <optional> */
-    { -1, insn_ds (62, 2, 1, 24, 0), 1 },
+    { static_cast<unsigned int>(-1), insn_ds (62, 2, 1, 24, 0), 1 },
 
     /* addis r11, r2, <any> */
     { insn_d (-1, -1, -1, 0), insn_d (15, 11, 2, 0), 0 },
@@ -295,7 +298,7 @@
     { insn_xfx (-1, -1, -1, -1), insn_xfx (31, 12, 9, 467), 0 },
 
     /* bctr */
-    { -1, 0x4e800420, 0 },
+    { static_cast<unsigned int>(-1), 0x4e800420, 0 },
 
     { 0, 0, 0 }
   };
@@ -305,7 +308,7 @@
 static struct ppc_insn_pattern ppc64_standard_linkage7[] =
   {
     /* std r2, 24(r1) <optional> */
-    { -1, insn_ds (62, 2, 1, 24, 0), 1 },
+    { static_cast<unsigned int>(-1), insn_ds (62, 2, 1, 24, 0), 1 },
 
     /* ld r12, <any>(r2) */
     { insn_ds (-1, -1, -1, 0, -1), insn_ds (58, 12, 2, 0, 0), 0 },
@@ -314,7 +317,7 @@
     { insn_xfx (-1, -1, -1, -1), insn_xfx (31, 12, 9, 467), 0 },
 
     /* bctr */
-    { -1, 0x4e800420, 0 },
+    { static_cast<unsigned int>(-1), 0x4e800420, 0 },
 
     { 0, 0, 0 }
   };
@@ -325,7 +328,7 @@
 static struct ppc_insn_pattern ppc64_standard_linkage8[] =
   {
     /* std r2, 24(r1) <optional> */
-    { -1, insn_ds (62, 2, 1, 24, 0), 1 },
+    { static_cast<unsigned int>(-1), insn_ds (62, 2, 1, 24, 0), 1 },
 
     /* addis r12, r2, <any> */
     { insn_d (-1, -1, -1, 0), insn_d (15, 12, 2, 0), 0 },
@@ -337,7 +340,7 @@
     { insn_xfx (-1, -1, -1, -1), insn_xfx (31, 12, 9, 467), 0 },
 
     /* bctr */
-    { -1, 0x4e800420, 0 },
+    { static_cast<unsigned int>(-1), 0x4e800420, 0 },
 
     { 0, 0, 0 }
   };
