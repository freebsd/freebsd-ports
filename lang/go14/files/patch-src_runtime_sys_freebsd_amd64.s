--- src/runtime/sys_freebsd_amd64.s.orig	2016-09-28 21:09:32.129553000 +0200
+++ src/runtime/sys_freebsd_amd64.s	2016-09-28 21:09:49.349817000 +0200
@@ -9,31 +9,6 @@
 #include "zasm_GOOS_GOARCH.h"
 #include "textflag.h"
 
-// FreeBSD 8, FreeBSD 9, and older versions that I have checked
-// do not restore R10 on exit from a "restarted" system call
-// if you use the SYSCALL instruction. This means that, for example,
-// if a signal arrives while the wait4 system call is executing,
-// the wait4 internally returns ERESTART, which makes the kernel
-// back up the PC to execute the SYSCALL instruction a second time.
-// However, since the kernel does not restore R10, the fourth
-// argument to the system call has been lost. (FreeBSD 9 also fails
-// to restore the fifth and sixth arguments, R8 and R9, although
-// some earlier versions did restore those correctly.)
-// The broken code is in fast_syscall in FreeBSD's amd64/amd64/exception.S.
-// It restores only DI, SI, DX, AX, and RFLAGS on system call return.
-// http://fxr.watson.org/fxr/source/amd64/amd64/exception.S?v=FREEBSD91#L399
-//
-// The INT $0x80 system call path (int0x80_syscall in FreeBSD's 
-// amd64/ia32/ia32_exception.S) does not have this problem,
-// but it expects the third argument in R10. Instead of rewriting
-// all the assembly in this file, #define SYSCALL to a safe simulation
-// using INT $0x80.
-//
-// INT $0x80 is a little slower than SYSCALL, but correctness wins.
-//
-// See golang.org/issue/6372.
-#define SYSCALL MOVQ R10, CX; INT $0x80
-	
 TEXT runtime·sys_umtx_op(SB),NOSPLIT,$0
 	MOVQ addr+0(FP), DI
 	MOVL mode+8(FP), SI
