--- bfd.orig/cpu-powerpc.c	Sun May 12 10:57:07 2002
+++ bfd/cpu-powerpc.c	Sun May 12 10:57:17 2002
@@ -50,6 +50,65 @@
 
 const bfd_arch_info_type bfd_powerpc_archs[] =
 {
+#if BFD_DEFAULT_TARGET_SIZE == 64 /* default arch must come first.  */
+  {
+    64,	/* 64 bits in a word */
+    64,	/* 64 bits in an address */
+    8,	/* 8 bits in a byte */
+    bfd_arch_powerpc,
+    bfd_mach_ppc64,
+    "powerpc",
+    "powerpc:common64",
+    3,
+    true, /* default for 64 bit target */
+    powerpc_compatible,
+    bfd_default_scan,
+    &bfd_powerpc_archs[1]
+  },
+  {
+    32,	/* 32 bits in a word */
+    32,	/* 32 bits in an address */
+    8,	/* 8 bits in a byte */
+    bfd_arch_powerpc,
+    bfd_mach_ppc, /* for the POWER/PowerPC common architecture */
+    "powerpc",
+    "powerpc:common",
+    3,
+    false,
+    powerpc_compatible,
+    bfd_default_scan,
+    &bfd_powerpc_archs[2],
+  },
+#else
+  {
+    32,	/* 32 bits in a word */
+    32,	/* 32 bits in an address */
+    8,	/* 8 bits in a byte */
+    bfd_arch_powerpc,
+    bfd_mach_ppc, /* for the POWER/PowerPC common architecture */
+    "powerpc",
+    "powerpc:common",
+    3,
+    true, /* default for 32 bit target */
+    powerpc_compatible,
+    bfd_default_scan,
+    &bfd_powerpc_archs[1],
+  },
+  {
+    64,	/* 64 bits in a word */
+    64,	/* 64 bits in an address */
+    8,	/* 8 bits in a byte */
+    bfd_arch_powerpc,
+    bfd_mach_ppc64,
+    "powerpc",
+    "powerpc:common64",
+    3,
+    false,
+    powerpc_compatible,
+    bfd_default_scan,
+    &bfd_powerpc_archs[2]
+  },
+#endif
   {
     32,	/* 32 bits in a word */
     32,	/* 32 bits in an address */
@@ -62,7 +121,7 @@
     false, /* not the default */
     powerpc_compatible,
     bfd_default_scan,
-    &bfd_powerpc_archs[1]
+    &bfd_powerpc_archs[3]
   },
   {
     32,	/* 32 bits in a word */
@@ -76,7 +135,7 @@
     false, /* not the default */
     powerpc_compatible,
     bfd_default_scan,
-    &bfd_powerpc_archs[2]
+    &bfd_powerpc_archs[4]
   },
   {
     32,	/* 32 bits in a word */
@@ -90,7 +149,7 @@
     false, /* not the default */
     powerpc_compatible,
     bfd_default_scan,
-    &bfd_powerpc_archs[3]
+    &bfd_powerpc_archs[5]
   },
   {
     32,	/* 32 bits in a word */
@@ -104,7 +163,7 @@
     false, /* not the default */
     powerpc_compatible,
     bfd_default_scan,
-    &bfd_powerpc_archs[4]
+    &bfd_powerpc_archs[6]
   },
   {
     32,	/* 32 bits in a word */
@@ -118,7 +177,7 @@
     false, /* not the default */
     powerpc_compatible,
     bfd_default_scan,
-    &bfd_powerpc_archs[5]
+    &bfd_powerpc_archs[7]
   },
   {
     64,	/* 64 bits in a word */
@@ -132,7 +191,7 @@
     false, /* not the default */
     powerpc_compatible,
     bfd_default_scan,
-    &bfd_powerpc_archs[6]
+    &bfd_powerpc_archs[8]
   },
   {
     64,	/* 64 bits in a word */
@@ -146,7 +205,7 @@
     false, /* not the default */
     powerpc_compatible,
     bfd_default_scan,
-    &bfd_powerpc_archs[7]
+    &bfd_powerpc_archs[9]
   },
   {
     64,	/* 64 bits in a word */
@@ -160,7 +219,7 @@
     false, /* not the default */
     powerpc_compatible,
     bfd_default_scan,
-    &bfd_powerpc_archs[8]
+    &bfd_powerpc_archs[10]
   },
   {
     64,	/* 64 bits in a word */
@@ -174,7 +233,7 @@
     false, /* not the default */
     powerpc_compatible,
     bfd_default_scan,
-    &bfd_powerpc_archs[9]
+    &bfd_powerpc_archs[11]
   },
   {
     64,	/* 64 bits in a word */
@@ -188,7 +247,7 @@
     false, /* not the default */
     powerpc_compatible,
     bfd_default_scan,
-    &bfd_powerpc_archs[10]
+    &bfd_powerpc_archs[12]
   },
   {
     32,	/* 32 bits in a word */
@@ -202,7 +261,7 @@
     false, /* not the default */
     powerpc_compatible,
     bfd_default_scan,
-    &bfd_powerpc_archs[11]
+    &bfd_powerpc_archs[13]
   },
   {
     32,       /* 32 bits in a word */
@@ -214,34 +273,6 @@
     "powerpc:MPC8XX",
     3,
     false, /* not the default */
-    powerpc_compatible,
-    bfd_default_scan,
-    &bfd_powerpc_archs[12]
-  },
-  {
-    64,	/* 64 bits in a word */
-    64,	/* 64 bits in an address */
-    8,	/* 8 bits in a byte */
-    bfd_arch_powerpc,
-    bfd_mach_ppc64,
-    "powerpc",
-    "powerpc:common64",
-    3,
-    BFD_DEFAULT_TARGET_SIZE == 64, /* default for 64 bit target */
-    powerpc_compatible,
-    bfd_default_scan,
-    &bfd_powerpc_archs[13]
-  },
-  {
-    32,	/* 32 bits in a word */
-    32,	/* 32 bits in an address */
-    8,	/* 8 bits in a byte */
-    bfd_arch_powerpc,
-    bfd_mach_ppc, /* for the POWER/PowerPC common architecture */
-    "powerpc",
-    "powerpc:common",
-    3,
-    BFD_DEFAULT_TARGET_SIZE != 64, /* default for 32 bit target */
     powerpc_compatible,
     bfd_default_scan,
     0
