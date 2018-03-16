--- gdb/i386-nbsd-tdep.c.orig	2018-03-15 10:50:06.446434000 +0100
+++ gdb/i386-nbsd-tdep.c	2018-03-15 11:04:42.700720000 +0100
@@ -106,19 +106,19 @@
   SIGTRAMP_FRAME,
   1,
   {
-    { 0x8d, -1 }, { 0x44, -1 }, { 0x24, -1 }, { 0x10, -1 },
+    { 0x8d, static_cast<ULONGEST>(-1) }, { 0x44, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) }, { 0x10, static_cast<ULONGEST>(-1) },
 			/* leal  0x10(%esp), %eax */
-    { 0x50, -1 },	/* pushl %eax */
-    { 0x50, -1 },	/* pushl %eax */
-    { 0xb8, -1 }, { 0x27, -1 }, {0x01, -1 }, {0x00, -1 }, {0x00, -1 },
+    { 0x50, static_cast<ULONGEST>(-1) },	/* pushl %eax */
+    { 0x50, static_cast<ULONGEST>(-1) },	/* pushl %eax */
+    { 0xb8, static_cast<ULONGEST>(-1) }, { 0x27, static_cast<ULONGEST>(-1) }, {0x01, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) },
 			/* movl  $0x127, %eax		# __sigreturn14 */
-    { 0xcd, -1 }, { 0x80, -1},
+    { 0xcd, static_cast<ULONGEST>(-1) }, { 0x80, static_cast<ULONGEST>(-1)},
 			/* int   $0x80 */
-    { 0xb8, -1 }, { 0x01, -1 }, {0x00, -1 }, {0x00, -1 }, {0x00, -1 },
+    { 0xb8, static_cast<ULONGEST>(-1) }, { 0x01, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) },
 			/* movl  $0x1, %eax		# exit */
-    { 0xcd, -1 }, { 0x80, -1},
+    { 0xcd, static_cast<ULONGEST>(-1) }, { 0x80, static_cast<ULONGEST>(-1)},
 			/* int   $0x80 */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   i386nbsd_sigtramp_cache_init
 };
@@ -128,21 +128,21 @@
   SIGTRAMP_FRAME,
   1,
   {
-    { 0x8d, -1 }, { 0x44, -1 }, { 0x24, -1 }, { 0x0c, -1 },
+    { 0x8d, static_cast<ULONGEST>(-1) }, { 0x44, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) }, { 0x0c, static_cast<ULONGEST>(-1) },
 			/* leal  0x0c(%esp), %eax */
-    { 0x89, -1 }, { 0x44, -1 }, { 0x24, -1 }, { 0x04, -1 },
+    { 0x89, static_cast<ULONGEST>(-1) }, { 0x44, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) }, { 0x04, static_cast<ULONGEST>(-1) },
 			/* movl  %eax, 0x4(%esp) */
-    { 0xb8, -1 }, { 0x27, -1 }, {0x01, -1 }, {0x00, -1 }, {0x00, -1 },
+    { 0xb8, static_cast<ULONGEST>(-1) }, { 0x27, static_cast<ULONGEST>(-1) }, {0x01, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) },
 			/* movl  $0x127, %eax		# __sigreturn14 */
-    { 0xcd, -1 }, { 0x80, -1},
+    { 0xcd, static_cast<ULONGEST>(-1) }, { 0x80, static_cast<ULONGEST>(-1)},
 			/* int   $0x80 */
-    { 0x89, -1 }, { 0x44, -1 }, { 0x24, -1 }, { 0x04, -1 },
+    { 0x89, static_cast<ULONGEST>(-1) }, { 0x44, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) }, { 0x04, static_cast<ULONGEST>(-1) },
 			/* movl  %eax, 0x4(%esp) */
-    { 0xb8, -1 }, { 0x01, -1 }, {0x00, -1 }, {0x00, -1 }, {0x00, -1 },
+    { 0xb8, static_cast<ULONGEST>(-1) }, { 0x01, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) },
 			/* movl  $0x1, %eax */
-    { 0xcd, -1 }, { 0x80, -1},
+    { 0xcd, static_cast<ULONGEST>(-1) }, { 0x80, static_cast<ULONGEST>(-1)},
 			/* int   $0x80 */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   i386nbsd_sigtramp_cache_init
 };
@@ -152,21 +152,22 @@
   SIGTRAMP_FRAME,
   1,
   {
-    { 0x8b, -1 }, { 0x44, -1 }, { 0x24, -1 }, { 0x08, -1 },
+    { 0x8b, static_cast<ULONGEST>(-1) }, { 0x44, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) }, { 0x08, static_cast<ULONGEST>(-1) },
 			/* movl  8(%esp),%eax */
-    { 0x89, -1 }, { 0x44, -1 }, { 0x24, -1 }, { 0x04, -1 },
+    { 0x89, static_cast<ULONGEST>(-1) }, { 0x44, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) }, { 0x04, static_cast<ULONGEST>(-1) },
 			/* movl  %eax, 0x4(%esp) */
-    { 0xb8, -1 }, { 0x34, -1 }, { 0x01, -1 }, { 0x00, -1 }, { 0x00, -1 },
+    { 0xb8, static_cast<ULONGEST>(-1) }, { 0x34, static_cast<ULONGEST>(-1) }, { 0x01, static_cast<ULONGEST>(-1) }, { 0x00, static_cast<ULONGEST>(-1) }, { 0x00, static_cast<ULONGEST>(-1) },
 			/* movl  $0x134, %eax            # setcontext */
-    { 0xcd, -1 }, { 0x80, -1 },
+    { 0xcd, static_cast<ULONGEST>(-1) }, { 0x80, static_cast<ULONGEST>(-1) },
 			/* int   $0x80 */
-    { 0x89, -1 }, { 0x44, -1 }, { 0x24, -1 }, { 0x04, -1 },
+    { 0x89, static_cast<ULONGEST>(-1) }, { 0x44, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) }, { 0x04, static_cast<ULONGEST>(-1) },
+    { 0x89, static_cast<ULONGEST>(-1) }, { 0x44, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) }, { 0x04, static_cast<ULONGEST>(-1) },
 			/* movl  %eax, 0x4(%esp) */
-    { 0xb8, -1 }, { 0x01, -1 }, { 0x00, -1 }, { 0x00, -1 }, { 0x00, -1 },
+    { 0xb8, static_cast<ULONGEST>(-1) }, { 0x01, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) },
 			/* movl  $0x1, %eax */
-    { 0xcd, -1 }, { 0x80, -1 },
+    { 0xcd, static_cast<ULONGEST>(-1) }, { 0x80, static_cast<ULONGEST>(-1)},
 			/* int   $0x80 */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   i386nbsd_sigtramp_cache_init
 };
@@ -176,22 +177,22 @@
   SIGTRAMP_FRAME,
   1,
   {
-    { 0x8d, -1 }, { 0x84, -1 }, { 0x24, -1 },
-        { 0x8c, -1 }, { 0x00, -1 }, { 0x00, -1 }, { 0x00, -1 },
+    { 0x8d, static_cast<ULONGEST>(-1) }, { 0x84, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) },
+        { 0x8c, static_cast<ULONGEST>(-1) }, { 0x00, static_cast<ULONGEST>(-1) }, { 0x00, static_cast<ULONGEST>(-1) }, { 0x00, static_cast<ULONGEST>(-1) },
 			/* leal  0x8c(%esp), %eax */
-    { 0x89, -1 }, { 0x44, -1 }, { 0x24, -1 }, { 0x04, -1 },
+    { 0x89, static_cast<ULONGEST>(-1) }, { 0x44, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) }, { 0x04, static_cast<ULONGEST>(-1) },
 			/* movl  %eax, 0x4(%esp) */
-    { 0xb8, -1 }, { 0x34, -1 }, { 0x01, -1 }, { 0x00, -1 }, { 0x00, -1 },
+    { 0xb8, static_cast<ULONGEST>(-1) }, { 0x34, static_cast<ULONGEST>(-1) }, { 0x01, static_cast<ULONGEST>(-1) }, { 0x00, static_cast<ULONGEST>(-1) }, { 0x00, static_cast<ULONGEST>(-1) },
 			/* movl  $0x134, %eax            # setcontext */
-    { 0xcd, -1 }, { 0x80, -1},
+    { 0xcd, static_cast<ULONGEST>(-1) }, { 0x80, static_cast<ULONGEST>(-1)},
 			/* int   $0x80 */
-    { 0x89, -1 }, { 0x44, -1 }, { 0x24, -1 }, { 0x04, -1 },
+    { 0x89, static_cast<ULONGEST>(-1) }, { 0x44, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) }, { 0x04, static_cast<ULONGEST>(-1) },
 			/* movl  %eax, 0x4(%esp) */
-    { 0xb8, -1 }, { 0x01, -1 }, {0x00, -1 }, {0x00, -1 }, {0x00, -1 },
+    { 0xb8, static_cast<ULONGEST>(-1) }, { 0x01, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) },
 			/* movl  $0x1, %eax */
-    { 0xcd, -1 }, { 0x80, -1},
+    { 0xcd, static_cast<ULONGEST>(-1) }, { 0x80, static_cast<ULONGEST>(-1)},
 			/* int   $0x80 */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   i386nbsd_sigtramp_cache_init
 };
@@ -201,23 +202,23 @@
   SIGTRAMP_FRAME,
   1,
   {
-    { 0x8d, -1 }, { 0x84, -1 }, { 0x24, -1 },
-        { 0x8c, -1 }, { 0x00, -1 }, { 0x00, -1 }, { 0x00, -1 },
+    { 0x8d, static_cast<ULONGEST>(-1) }, { 0x84, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) },
+        { 0x8c, static_cast<ULONGEST>(-1) }, { 0x00, static_cast<ULONGEST>(-1) }, { 0x00, static_cast<ULONGEST>(-1) }, { 0x00, static_cast<ULONGEST>(-1) },
 			/* leal  0x8c(%esp), %eax */
-    { 0x89, -1 }, { 0x44, -1 }, { 0x24, -1 }, { 0x04, -1 },
+    { 0x89, static_cast<ULONGEST>(-1) }, { 0x44, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) }, { 0x04, static_cast<ULONGEST>(-1) },
 			/* movl  %eax, 0x4(%esp) */
-    { 0xb8, -1 }, { 0x34, -1 }, { 0x01, -1 }, { 0x00, -1 }, { 0x00, -1 },
+    { 0xb8, static_cast<ULONGEST>(-1) }, { 0x34, static_cast<ULONGEST>(-1) }, { 0x01, static_cast<ULONGEST>(-1) }, { 0x00, static_cast<ULONGEST>(-1) }, { 0x00, static_cast<ULONGEST>(-1) },
 			/* movl  $0x134, %eax            # setcontext */
-    { 0xcd, -1 }, { 0x80, -1},
+    { 0xcd, static_cast<ULONGEST>(-1) }, { 0x80, static_cast<ULONGEST>(-1)},
 			/* int   $0x80 */
-    { 0xc7, -1 }, { 0x44, -1 }, { 0x24, -1 }, { 0x04, -1 },
-        { 0xff, -1 }, { 0xff, -1 }, { 0xff, -1 }, { 0xff, -1 },
+    { 0xc7, static_cast<ULONGEST>(-1) }, { 0x44, static_cast<ULONGEST>(-1) }, { 0x24, static_cast<ULONGEST>(-1) }, { 0x04, static_cast<ULONGEST>(-1) },
+        { 0xff, static_cast<ULONGEST>(-1) }, { 0xff, static_cast<ULONGEST>(-1) }, { 0xff, static_cast<ULONGEST>(-1) }, { 0xff, static_cast<ULONGEST>(-1) },
 			/* movl   $0xffffffff,0x4(%esp) */
-    { 0xb8, -1 }, { 0x01, -1 }, {0x00, -1 }, {0x00, -1 }, {0x00, -1 },
+    { 0xb8, static_cast<ULONGEST>(-1) }, { 0x01, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) }, {0x00, static_cast<ULONGEST>(-1) },
 			/* movl  $0x1, %eax */
-    { 0xcd, -1 }, { 0x80, -1},
+    { 0xcd, static_cast<ULONGEST>(-1) }, { 0x80, static_cast<ULONGEST>(-1)},
 			/* int   $0x80 */
-    { TRAMP_SENTINEL_INSN, -1 }
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   i386nbsd_sigtramp_cache_init
 };
