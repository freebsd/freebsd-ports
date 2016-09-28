--- src/syscall/asm_freebsd_amd64.s.orig	2016-09-28 21:09:22.758123000 +0200
+++ src/syscall/asm_freebsd_amd64.s	2016-09-28 21:10:03.281763000 +0200
@@ -12,11 +12,6 @@
 // System call support for AMD64, FreeBSD
 //
 
-// The SYSCALL variant for invoking system calls is broken in FreeBSD.
-// See comment at top of ../runtime/sys_freebsd_amd64.c and
-// golang.org/issue/6372.
-#define SYSCALL MOVQ R10, CX; INT $0x80
-
 // func Syscall(trap int64, a1, a2, a3 int64) (r1, r2, err int64);
 // func Syscall6(trap int64, a1, a2, a3, a4, a5, a6 int64) (r1, r2, err int64);
 // func Syscall9(trap int64, a1, a2, a3, a4, a5, a6, a7, a8, a9 int64) (r1, r2, err int64)
