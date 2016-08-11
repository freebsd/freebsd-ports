--- src/nvcore/Debug.cpp.orig	2010-05-15 09:12:05 UTC
+++ src/nvcore/Debug.cpp
@@ -34,7 +34,7 @@
 #	endif
 #endif
 
-#if NV_OS_DARWIN
+#if NV_OS_DARWIN || NV_OS_FREEBSD
 #	include <unistd.h>	// getpid
 #	include <sys/types.h>
 #	include <sys/sysctl.h>	// sysctl
@@ -199,6 +199,14 @@ namespace 
 				return (void *) ucp->uc_mcontext->ss.eip;
 #			endif
 #		endif
+#	elif NV_OS_FREEBSD
+#		if NV_CPU_X86_64
+			ucontext_t * ucp = (ucontext_t *)secret;
+			return (void *)ucp->uc_mcontext.mc_rip;
+#		elif NV_CPU_X86
+			ucontext_t * ucp = (ucontext_t *)secret;
+			return (void *)ucp->uc_mcontext.mc_eip;
+#		endif
 #	else
 #		if NV_CPU_X86_64
 			// #define REG_RIP REG_INDEX(rip) // seems to be 16
