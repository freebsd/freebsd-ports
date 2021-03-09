--- src/VBox/VMM/VMMR0/GVMMR0.cpp.orig	2020-05-13 19:44:47 UTC
+++ src/VBox/VMM/VMMR0/GVMMR0.cpp
@@ -1243,7 +1243,7 @@ static void gvmmR0CleanupVM(PGVM pGVM)
 
     GMMR0CleanupVM(pGVM);
 
-    AssertCompile((uintptr_t)NIL_RTTHREADCTXHOOK == 0); /* Depends on zero initialized memory working for NIL at the moment. */
+    AssertCompile(NIL_RTTHREADCTXHOOK == (RTTHREADCTXHOOK)0); /* Depends on zero initialized memory working for NIL at the moment. */
     for (VMCPUID idCpu = 0; idCpu < pGVM->cCpus; idCpu++)
     {
         /** @todo Can we busy wait here for all thread-context hooks to be
