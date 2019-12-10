--- m4/pc_from_ucontext.m4.orig	2019-09-01 20:36:55 UTC
+++ m4/pc_from_ucontext.m4
@@ -21,6 +21,7 @@ AC_DEFUN([AC_PC_FROM_UCONTEXT],
    pc_fields="$pc_fields uc_mcontext.gregs[[R15]]"     # Linux (arm old [untested])
    pc_fields="$pc_fields uc_mcontext.arm_pc"           # Linux (arm new [untested])
    pc_fields="$pc_fields uc_mcontext.mc_eip"           # FreeBSD (i386)
+   pc_fields="$pc_fields uc_mcontext.mc_srr0"          # FreeBSD (powerpc, powerpc64)
    pc_fields="$pc_fields uc_mcontext.mc_rip"           # FreeBSD (x86_64 [untested])
    pc_fields="$pc_fields uc_mcontext.__gregs[[_REG_EIP]]"  # NetBSD (i386)
    pc_fields="$pc_fields uc_mcontext.__gregs[[_REG_RIP]]"  # NetBSD (x86_64)
