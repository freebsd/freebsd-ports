2017-11-05  Andreas Tobler  <andreast@gcc.gnu.org>

	Backport from mainline
	2017-11-04  Andreas Tobler  <andreast@gcc.gnu.org>

	PR libgcc/82635
	* config/i386/freebsd-unwind.h (MD_FALLBACK_FRAME_STATE_FOR): Use a
	sysctl to determine whether we're in a trampoline.
	Keep the pattern matching method for systems without
	KERN_PROC_SIGTRAMP sysctl.

--- UTC
--- libgcc/config/i386/freebsd-unwind.h	2017/11/05 17:24:37	254430
+++ libgcc/config/i386/freebsd-unwind.h	2017/11/05 19:30:41	254431
@@ -28,7 +28,10 @@
 
 #include <sys/types.h>
 #include <signal.h>
+#include <unistd.h>
+#include <sys/sysctl.h>
 #include <sys/ucontext.h>
+#include <sys/user.h>
 #include <machine/sigframe.h>
 
 #define REG_NAME(reg)	sf_uc.uc_mcontext.mc_## reg
@@ -36,6 +39,38 @@
 #ifdef __x86_64__
 #define MD_FALLBACK_FRAME_STATE_FOR x86_64_freebsd_fallback_frame_state
 
+#ifdef KERN_PROC_SIGTRAMP
+/* FreeBSD past 9.3 provides a kern.proc.sigtramp.<pid> sysctl that
+   returns the location of the signal trampoline. Use this to find
+   out whether we're in a trampoline.
+*/
+static int
+x86_64_outside_sigtramp_range (unsigned char *pc)
+{
+  static int sigtramp_range_determined = 0;
+  static unsigned char *sigtramp_start, *sigtramp_end;
+
+  if (sigtramp_range_determined == 0)
+    {
+      struct kinfo_sigtramp kst = {0};
+      size_t len = sizeof (kst);
+      int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_SIGTRAMP, getpid() };
+
+      sigtramp_range_determined = 1;
+      if (sysctl (mib, 4, &kst, &len, NULL, 0) == 0)
+      {
+        sigtramp_range_determined = 2;
+        sigtramp_start = kst.ksigtramp_start;
+        sigtramp_end   = kst.ksigtramp_end;
+      }
+    }
+  if (sigtramp_range_determined < 2)  /* sysctl failed if < 2 */
+    return 1;
+
+  return (pc < sigtramp_start || pc >= sigtramp_end);
+}
+#endif
+
 static _Unwind_Reason_Code
 x86_64_freebsd_fallback_frame_state
 (struct _Unwind_Context *context, _Unwind_FrameState *fs)
@@ -43,6 +78,7 @@
   struct sigframe *sf;
   long new_cfa;
 
+#ifndef KERN_PROC_SIGTRAMP
   /* Prior to FreeBSD 9, the signal trampoline was located immediately
      before the ps_strings.  To support non-executable stacks on AMD64,
      the sigtramp was moved to a shared page for FreeBSD 9.  Unfortunately
@@ -62,12 +98,15 @@
         && *(unsigned int *)(context->ra +  8) == 0x01a1c0c7
         && *(unsigned int *)(context->ra + 12) == 0x050f0000 ))
     return _URC_END_OF_STACK;
+#else
+  if (x86_64_outside_sigtramp_range(context->ra))
+    return _URC_END_OF_STACK;
+#endif
 
   sf = (struct sigframe *) context->cfa;
   new_cfa = sf->REG_NAME(rsp);
   fs->regs.cfa_how = CFA_REG_OFFSET;
-  /* Register 7 is rsp  */
-  fs->regs.cfa_reg = 7;
+  fs->regs.cfa_reg =  __LIBGCC_STACK_POINTER_REGNUM__;
   fs->regs.cfa_offset = new_cfa - (long) context->cfa;
 
   /* The SVR4 register numbering macros aren't usable in libgcc.  */
