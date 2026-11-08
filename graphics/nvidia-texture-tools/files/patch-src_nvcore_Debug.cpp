--- src/nvcore/Debug.cpp.orig	2020-08-24 06:27:21 UTC
+++ src/nvcore/Debug.cpp
@@ -628,6 +628,12 @@ namespace 
 #  elif NV_CPU_X86
         ucontext_t * ucp = (ucontext_t *)secret;
         return (void *)ucp->uc_mcontext.mc_eip;
+#  elif NV_CPU_PPC
+        ucontext_t * ucp = (ucontext_t *)secret;
+        return (void *)ucp->uc_mcontext.mc_srr0;
+#  elif NV_CPU_ARM_64
+        ucontext_t * ucp = (ucontext_t *)secret;
+        return (void *)ucp->uc_mcontext.mc_gpregs.gp_elr;
 #    else
 #      error "Unknown CPU"
 #    endif
