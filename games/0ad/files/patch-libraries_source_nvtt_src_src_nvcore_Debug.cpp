--- libraries/source/nvtt/src/src/nvcore/Debug.cpp.orig	2021-02-28 23:45:14 UTC
+++ libraries/source/nvtt/src/src/nvcore/Debug.cpp
@@ -628,6 +628,9 @@ namespace 
 #  elif NV_CPU_X86
         ucontext_t * ucp = (ucontext_t *)secret;
         return (void *)ucp->uc_mcontext.mc_eip;
+#  elif NV_CPU_PPC
+        ucontext_t * ucp = (ucontext_t *)secret;
+        return (void *)ucp->uc_mcontext.mc_srr0;
 #    else
 #      error "Unknown CPU"
 #    endif
