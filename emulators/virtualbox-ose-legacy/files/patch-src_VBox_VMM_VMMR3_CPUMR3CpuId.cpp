--- src/VBox/VMM/VMMR3/CPUMR3CpuId.cpp.orig	2016-07-18 11:57:09 UTC
+++ src/VBox/VMM/VMMR3/CPUMR3CpuId.cpp
@@ -3797,6 +3797,10 @@ static int cpumR3CpuIdReadConfig(PVM pVM
     rc = cpumR3CpuIdReadIsaExtCfgLegacy(pVM, pIsaExts, pCpumCfg, "SSE4.2", &pConfig->enmSse42, true);
     AssertLogRelRCReturn(rc, rc);
 
+#ifdef __FreeBSD__
+    // XXX PR211651: Disable XSAVE/XRSTOR for guest
+    bool const fMayHaveXSave = false;
+#else
     bool const fMayHaveXSave = fNestedPagingAndFullGuestExec
                             && pVM->cpum.s.HostFeatures.fXSaveRstor
                             && pVM->cpum.s.HostFeatures.fOpSysXSaveRstor
@@ -3804,6 +3808,7 @@ static int cpumR3CpuIdReadConfig(PVM pVM
                             && !HMIsLongModeAllowed(pVM)
 #endif
                             ;
+#endif
     uint64_t const fXStateHostMask = pVM->cpum.s.fXStateHostMask;
 
     /** @cfgm{/CPUM/IsaExts/XSAVE, boolean, depends}
