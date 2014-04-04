--- ./xlib/inlstring.h.orig	1998-03-04 19:59:19.000000000 +0100
+++ ./xlib/inlstring.h	2014-03-30 03:11:00.579428909 +0200
@@ -238,12 +238,12 @@
 static INLINE void *
 __memcpy_aligndest (void *dest, const void *src, int n)
 {
-  __asm__         __volatile__ ("
-				cmpl $3, %%ecx
-				ja 1f
-				call * __memcpy_jumptable (, %%ecx, 4)
-				jmp 2f
-				1:call __memcpyasm_regargs
+  __asm__         __volatile__ ("\
+				cmpl $3, %%ecx \
+				ja 1f \
+				call * __memcpy_jumptable (, %%ecx, 4) \
+				jmp 2f \
+				1:call __memcpyasm_regargs \
 				"
 				:
 				:"b"            (dest), "d" (src), "c" (n)
@@ -255,13 +255,13 @@
 static INLINE void *
 __memcpy_destaligned (void *dest, const void *src, int n)
 {
-  __asm__         __volatile__ ("
-				cmpl $32, %%ecx
-				ja 1f
-				call * __memcpy_jumptable (, %%ecx, 4)
-				jmp 2f
-				1:call __memcpyasm_regargs_aligned
-				2:
+  __asm__         __volatile__ ("\
+				cmpl $32, %%ecx \
+				ja 1f \
+				call * __memcpy_jumptable (, %%ecx, 4) \
+				jmp 2f \
+				1:call __memcpyasm_regargs_aligned \
+				2: \
 				"
 				:
 				:"b"            (dest), "d" (src), "c" (n)
@@ -273,13 +273,13 @@
 static INLINE void *
 __memcpy_balanced (void *dest, const void *src, int n)
 {
-  __asm__         __volatile__ ("
-				cmpl $19, %%ecx
-				ja 1f
-				call * __memcpy_jumptable (, %%ecx, 4)
-				jmp 2f
-				1:call __memcpyasm_regargs
-				2:
+  __asm__         __volatile__ ("\
+				cmpl $19, %%ecx \
+				ja 1f \
+				call * __memcpy_jumptable (, %%ecx, 4) \
+				jmp 2f \
+				1:call __memcpyasm_regargs \
+				2: \
 				"
 				:
 	     :"b"            ((long) dest), "d" ((long) src), "c" ((long) n)
