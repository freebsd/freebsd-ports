--- libraries/source/nvtt/nvtt-28209/src/src/nvcore/Debug.cpp.orig	2025-01-30 19:39:40 UTC
+++ libraries/source/nvtt/nvtt-28209/src/src/nvcore/Debug.cpp
@@ -631,6 +631,9 @@ namespace 
 #  elif NV_CPU_X86
         ucontext_t * ucp = (ucontext_t *)secret;
         return (void *)ucp->uc_mcontext.mc_eip;
+#  elif NV_CPU_PPC
+        ucontext_t * ucp = (ucontext_t *)secret;
+        return (void *)ucp->uc_mcontext.mc_srr0;
 #    else
 #      error "Unknown CPU"
 #    endif
