--- rts/StgCRunAsm.S.orig
+++ rts/StgCRunAsm.S
@@ -6,7 +6,7 @@
 #if !defined(USE_MINIINTERPRETER)
 
 #if defined(powerpc64le_HOST_ARCH)
-# if defined(linux_HOST_OS)
+# if defined(linux_HOST_OS) || defined(freebsd_HOST_OS)
 /* 64-bit PowerPC ELF V2 ABI Revision 1.4
  *
  * Stack frame organization (see Figure 2.18, ELF V2 ABI Revision 1.4, p 31)
@@ -66,6 +66,94 @@
         addi 12,1,-(8*18)
         bl _restgpr1_14
         b _restfpr_14
+#  if defined(freebsd_HOST_OS)
+/* GNU ld synthesizes the ELFv2 out-of-line register save/restore
+ * routines that StgRun/StgReturn call above; clang/lld do not.  Provide
+ * them here.  Bodies match the GNU ld (binutils 2.44) synthesis. */
+_savegpr1_14:
+	std 14,-144(12)
+	std 15,-136(12)
+	std 16,-128(12)
+	std 17,-120(12)
+	std 18,-112(12)
+	std 19,-104(12)
+	std 20,-96(12)
+	std 21,-88(12)
+	std 22,-80(12)
+	std 23,-72(12)
+	std 24,-64(12)
+	std 25,-56(12)
+	std 26,-48(12)
+	std 27,-40(12)
+	std 28,-32(12)
+	std 29,-24(12)
+	std 30,-16(12)
+	std 31,-8(12)
+	blr
+_savefpr_14:
+	stfd 14,-144(1)
+	stfd 15,-136(1)
+	stfd 16,-128(1)
+	stfd 17,-120(1)
+	stfd 18,-112(1)
+	stfd 19,-104(1)
+	stfd 20,-96(1)
+	stfd 21,-88(1)
+	stfd 22,-80(1)
+	stfd 23,-72(1)
+	stfd 24,-64(1)
+	stfd 25,-56(1)
+	stfd 26,-48(1)
+	stfd 27,-40(1)
+	stfd 28,-32(1)
+	stfd 29,-24(1)
+	stfd 30,-16(1)
+	stfd 31,-8(1)
+	std 0,16(1)
+	blr
+_restgpr1_14:
+	ld 14,-144(12)
+	ld 15,-136(12)
+	ld 16,-128(12)
+	ld 17,-120(12)
+	ld 18,-112(12)
+	ld 19,-104(12)
+	ld 20,-96(12)
+	ld 21,-88(12)
+	ld 22,-80(12)
+	ld 23,-72(12)
+	ld 24,-64(12)
+	ld 25,-56(12)
+	ld 26,-48(12)
+	ld 27,-40(12)
+	ld 28,-32(12)
+	ld 29,-24(12)
+	ld 30,-16(12)
+	ld 31,-8(12)
+	blr
+_restfpr_14:
+	lfd 14,-144(1)
+	lfd 15,-136(1)
+	lfd 16,-128(1)
+	lfd 17,-120(1)
+	lfd 18,-112(1)
+	lfd 19,-104(1)
+	lfd 20,-96(1)
+	lfd 21,-88(1)
+	lfd 22,-80(1)
+	lfd 23,-72(1)
+	lfd 24,-64(1)
+	lfd 25,-56(1)
+	lfd 26,-48(1)
+	lfd 27,-40(1)
+	lfd 28,-32(1)
+	ld 0,16(1)
+	lfd 29,-24(1)
+	mtlr 0
+	lfd 30,-16(1)
+	lfd 31,-8(1)
+	blr
+#  endif
 # else // linux_HOST_OS
 # error Only Linux support for power64 little endian right now.
 # endif
