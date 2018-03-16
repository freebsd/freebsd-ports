--- gdb/hppa-nbsd-tdep.c.orig	2018-03-15 15:58:14.876431000 +0100
+++ gdb/hppa-nbsd-tdep.c	2018-03-15 16:00:44.247395000 +0100
@@ -71,25 +71,25 @@
   SIGTRAMP_FRAME,
   4,
   {
-    { 0xc7d7c012, -1 },	/*	bb,>=,n %arg3, 30, 1f		*/
-    { 0xd6e01c1e, -1 },	/*	 depwi 0,31,2,%arg3		*/
-    { 0x0ee81093, -1 },	/*	ldw 4(%arg3), %r19		*/
-    { 0x0ee01097, -1 },	/*	ldw 0(%arg3), %arg3		*/
+    { 0xc7d7c012, static_cast<ULONGEST>(-1) },	/*	bb,>=,n %arg3, 30, 1f		*/
+    { 0xd6e01c1e, static_cast<ULONGEST>(-1) },	/*	 depwi 0,31,2,%arg3		*/
+    { 0x0ee81093, static_cast<ULONGEST>(-1) },	/*	ldw 4(%arg3), %r19		*/
+    { 0x0ee01097, static_cast<ULONGEST>(-1) },	/*	ldw 0(%arg3), %arg3		*/
 			/* 1: 					*/
-    { 0xe8404000, -1 },	/* 	blr %r0, %rp			*/
-    { 0xeae0c002, -1 },	/*	bv,n %r0(%arg3)			*/
-    { 0x08000240, -1 },	/*	 nop				*/
+    { 0xe8404000, static_cast<ULONGEST>(-1) },	/* 	blr %r0, %rp			*/
+    { 0xeae0c002, static_cast<ULONGEST>(-1) },	/*	bv,n %r0(%arg3)			*/
+    { 0x08000240, static_cast<ULONGEST>(-1) },	/*	 nop				*/
 
-    { 0x0803025a, -1 },	/*	copy %r3, %arg0			*/
-    { 0x20200801, -1 },	/*	ldil -40000000, %r1		*/
-    { 0xe420e008, -1 },	/*	be,l 4(%sr7, %r1), %sr0, %r31	*/
-    { 0x34160268, -1 },	/*	 ldi 134, %t1 ; SYS_setcontext	*/
+    { 0x0803025a, static_cast<ULONGEST>(-1) },	/*	copy %r3, %arg0			*/
+    { 0x20200801, static_cast<ULONGEST>(-1) },	/*	ldil -40000000, %r1		*/
+    { 0xe420e008, static_cast<ULONGEST>(-1) },	/*	be,l 4(%sr7, %r1), %sr0, %r31	*/
+    { 0x34160268, static_cast<ULONGEST>(-1) },	/*	 ldi 134, %t1 ; SYS_setcontext	*/
 
-    { 0x081c025a, -1 },	/*	copy ret0, %arg0		*/
-    { 0x20200801, -1 },	/*	ldil -40000000, %r1		*/
-    { 0xe420e008, -1 },	/*	be,l 4(%sr7, %r1), %sr0, %r31	*/
-    { 0x34160002, -1 },	/*	 ldi 1, %t1 ; SYS_exit		*/
-    { TRAMP_SENTINEL_INSN, -1 }
+    { 0x081c025a, static_cast<ULONGEST>(-1) },	/*	copy ret0, %arg0		*/
+    { 0x20200801, static_cast<ULONGEST>(-1) },	/*	ldil -40000000, %r1		*/
+    { 0xe420e008, static_cast<ULONGEST>(-1) },	/*	be,l 4(%sr7, %r1), %sr0, %r31	*/
+    { 0x34160002, static_cast<ULONGEST>(-1) },	/*	 ldi 1, %t1 ; SYS_exit		*/
+    { TRAMP_SENTINEL_INSN, static_cast<ULONGEST>(-1) }
   },
   hppanbsd_sigtramp_cache_init
 };
