--- code/qcommon/vm_x86.c.orig	2008-08-17 23:22:06 UTC
+++ code/qcommon/vm_x86.c
@@ -36,7 +36,25 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 /* need this on NX enabled systems (i386 with PAE kernel or
  * noexec32=on x86_64) */
-#ifdef __linux__
+//     Rambetter's note: I'm adding the test for __FreeBSD__ in addition to the [already
+// existing] test for __linux__.  Here is why.  I own a 32 bit FreeBSD 8.0 server with
+// a PAE kernel.  Without VM_X86_MMAP, ioq3ded segfaults shortly after starting
+// (this should come as no surprise).  With VM_X86_MMAP, ioq3ded runs very smoothly.
+// So, at a very minimum, we need to set VM_X86_MMAP for FreeBSD PAE kernels.
+//     Now, I also happen to own a 32 bit FreeBSD 7.1 server with just the standard kernel
+// (non-PAE).  I have run ioq3ded successfully on it with and without VM_X86_MMAP for many
+// months.  So, in the case of non-PAE FreeBSD, we can go either way - use VM_X86_MMAP or
+// not use it.  The absolute safest fix to this problem is to only set VM_X86_MMAP on
+// PAE FreeBSD kernels (in addition to Linux); however, I don't know of a way to detect
+// the PAE kernel easily.  Therefore, since using VM_X86_MMAP won't break anything on
+// non-PAE kernels [apparently], we'll just use it all the time on FreeBSD 32 bit.
+//     Now, you may ask the question: Why not change the entire test for just __unix__?
+// Unfortunately I cannot say anything about this because I don't have access to every
+// other system that has __unix__ defined, so I cannot possibly test all those cases to
+// make sure things work.  We'll just leave it with __linux__ and __FreeBSD__ to be safe.
+// If someone with a different flavor of UNIX running a PAE kernel has this problem too,
+// they can report the bug and we will adjust the line below accordingly.
+#if defined(__linux__) || defined(__FreeBSD__)
 #define VM_X86_MMAP
 #endif
 
@@ -90,7 +108,11 @@ void AsmCall(void);
 static void (*const asmCallPtr)(void) = AsmCall;
 
 
+#ifdef __clang__
+	int		callMask = 0;
+#else
 static	int		callMask = 0;
+#endif
 
 static	int	instruction, pass;
 static	int	lastConst = 0;
