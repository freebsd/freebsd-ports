Index: src/VBox/VMM/VMMR0/GMMR0.cpp
===================================================================
--- src/VBox/VMM/VMMR0/GMMR0.cpp	(Revision 58727)
+++ src/VBox/VMM/VMMR0/GMMR0.cpp	(Arbeitskopie)
@@ -661,7 +661,7 @@
         else
             SUPR0Printf("GMMR0Init: RTR0MemObjAllocPhysNC(,64K,Any) -> %d!\n", rc);
 #else
-# ifdef RT_OS_WINDOWS
+# if defined(RT_OS_WINDOWS) || defined(RT_OS_FREEBSD)
         pGMM->fLegacyAllocationMode = false;
 # else
         pGMM->fLegacyAllocationMode = true;
