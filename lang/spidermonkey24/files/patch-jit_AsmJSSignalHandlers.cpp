https://hg.mozilla.org/mozilla-central/rev/07ce4364fbec

--- jit/AsmJSSignalHandlers.cpp.orig	2013-10-29 21:40:19.000000000 +0100
+++ jit/AsmJSSignalHandlers.cpp	2015-01-25 11:23:43.104097667 +0100
@@ -64,7 +64,6 @@
 # endif
 # define EIP_sig(p) ((p)->uc_mcontext.gregs[REG_EIP])
 # define RIP_sig(p) ((p)->uc_mcontext.gregs[REG_RIP])
-# define PC_sig(p) ((p)->uc_mcontext.arm_pc)
 # define RAX_sig(p) ((p)->uc_mcontext.gregs[REG_RAX])
 # define RCX_sig(p) ((p)->uc_mcontext.gregs[REG_RCX])
 # define RDX_sig(p) ((p)->uc_mcontext.gregs[REG_RDX])
@@ -80,7 +79,11 @@
 # define R12_sig(p) ((p)->uc_mcontext.gregs[REG_R12])
 # define R13_sig(p) ((p)->uc_mcontext.gregs[REG_R13])
 # define R14_sig(p) ((p)->uc_mcontext.gregs[REG_R14])
-# define R15_sig(p) ((p)->uc_mcontext.gregs[REG_R15])
+# if defined(__linux__) && defined(__arm__)
+#  define R15_sig(p) ((p)->uc_mcontext.arm_pc)
+# else
+#  define R15_sig(p) ((p)->uc_mcontext.gregs[REG_R15])
+# endif
 #elif defined(__NetBSD__)
 # define XMM_sig(p,i) (((struct fxsave64 *)(p)->uc_mcontext.__fpregs)->fx_xmm[i])
 # define EIP_sig(p) ((p)->uc_mcontext.__gregs[_REG_EIP])
@@ -124,7 +127,11 @@
 # define R12_sig(p) ((p)->uc_mcontext.mc_r12)
 # define R13_sig(p) ((p)->uc_mcontext.mc_r13)
 # define R14_sig(p) ((p)->uc_mcontext.mc_r14)
-# define R15_sig(p) ((p)->uc_mcontext.mc_r15)
+# if defined(__FreeBSD__) && defined(__arm__)
+#  define R15_sig(p) ((p)->uc_mcontext.__gregs[_REG_R15])
+# else
+#  define R15_sig(p) ((p)->uc_mcontext.mc_r15)
+# endif
 #elif defined(XP_MACOSX)
 // Mach requires special treatment.
 #else
@@ -325,20 +332,20 @@
 #  define CONTEXT ucontext_t
 # endif
 
+#if defined(JS_CPU_X64)
+# define PC_sig(p) RIP_sig(p)
+#elif defined(JS_CPU_X86)
+# define PC_sig(p) EIP_sig(p)
+#elif defined(JS_CPU_ARM)
+# define PC_sig(p) R15_sig(p)
+#endif
+
 # if !defined(XP_MACOSX)
 static uint8_t **
 ContextToPC(CONTEXT *context)
 {
-#  if defined(JS_CPU_X64)
-    JS_STATIC_ASSERT(sizeof(RIP_sig(context)) == sizeof(void*));
-    return reinterpret_cast<uint8_t**>(&RIP_sig(context));
-#  elif defined(JS_CPU_X86)
-    JS_STATIC_ASSERT(sizeof(EIP_sig(context)) == sizeof(void*));
-    return reinterpret_cast<uint8_t**>(&EIP_sig(context));
-#  elif defined(JS_CPU_ARM)
     JS_STATIC_ASSERT(sizeof(PC_sig(context)) == sizeof(void*));
     return reinterpret_cast<uint8_t**>(&PC_sig(context));
-#  endif
 }
 
 #  if defined(JS_CPU_X64)
