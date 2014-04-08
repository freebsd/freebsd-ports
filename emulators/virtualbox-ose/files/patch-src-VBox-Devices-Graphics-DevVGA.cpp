--- src/VBox/Devices/Graphics/DevVGA.cpp.orig	2014-03-26 15:17:10.000000000 -0400
+++ src/VBox/Devices/Graphics/DevVGA.cpp	2014-04-02 16:41:47.000000000 -0400
@@ -5196,10 +5196,12 @@
     PVGASTATE pThis = (PVGASTATE)pvUser;
     NOREF(pDevIns);
 
+#ifdef VBOX_WITH_WDDM
     if (pThis->fScanLineCfg & VBVASCANLINECFG_ENABLE_VSYNC_IRQ)
     {
         VBVARaiseIrq(pThis, HGSMIHOSTFLAGS_VSYNC);
     }
+#endif
 
     if (pThis->pDrv)
         pThis->pDrv->pfnRefresh(pThis->pDrv);
@@ -5211,7 +5213,9 @@
     vbvaTimerCb(pThis);
 #endif
 
+#ifdef VBOX_WITH_VDMA
     vboxCmdVBVACmdTimer(pThis);
+#endif
 }
 
 #ifdef VBOX_WITH_VMSVGA
@@ -5365,26 +5369,30 @@
 static DECLCALLBACK(int) vgaR3SaveExec(PPDMDEVINS pDevIns, PSSMHANDLE pSSM)
 {
     PVGASTATE pThis = PDMINS_2_DATA(pDevIns, PVGASTATE);
+
 #ifdef VBOX_WITH_VDMA
     vboxVDMASaveStateExecPrep(pThis->pVdma, pSSM);
 #endif
+
     vgaR3SaveConfig(pThis, pSSM);
     vga_save(pSSM, PDMINS_2_DATA(pDevIns, PVGASTATE));
+
 #ifdef VBOX_WITH_HGSMI
     SSMR3PutBool(pSSM, true);
     int rc = vboxVBVASaveStateExec(pDevIns, pSSM);
 # ifdef VBOX_WITH_VDMA
     vboxVDMASaveStateExecDone(pThis->pVdma, pSSM);
 # endif
-    return rc;
 #else
-    SSMR3PutBool(pSSM, false);
+    int rc = SSMR3PutBool(pSSM, false);
 #endif
+
 #ifdef VBOX_WITH_VMSVGA
     if (    rc == VINF_SUCCESS
         &&  pThis->fVMSVGAEnabled)
         rc = vmsvgaSaveExec(pDevIns, pSSM);
 #endif
+
     return rc;
 }
 
@@ -5476,8 +5484,10 @@
     char           *pchEnd;
     LogFlow(("vgaReset\n"));
 
+#ifdef VBOX_WITH_VDMA
     if (pThis->pVdma)
         vboxVDMAReset(pThis->pVdma);
+#endif
 
 #ifdef VBOX_WITH_HGSMI
     VBVAReset(pThis);
@@ -5924,12 +5934,14 @@
 # if defined(VBOX_WITH_VIDEOHWACCEL)
     pThis->IVBVACallbacks.pfnVHWACommandCompleteAsynch = vbvaVHWACommandCompleteAsynch;
 # endif
-#if defined(VBOX_WITH_CRHGSMI)
+# if defined(VBOX_WITH_CRHGSMI)
     pThis->IVBVACallbacks.pfnCrHgsmiCommandCompleteAsync = vboxVDMACrHgsmiCommandCompleteAsync;
     pThis->IVBVACallbacks.pfnCrHgsmiControlCompleteAsync = vboxVDMACrHgsmiControlCompleteAsync;
 # endif
-#endif
+# if defined(VBOX_WITH_VIDEOHWACCEL) || defined(VBOX_WITH_CRHGSMI)
     pThis->IVBVACallbacks.pfnCrCtlSubmit = vboxCmdVBVACmdHostCtl;
+# endif
+#endif
 
     /*
      * We use our own critical section to avoid unncessary pointer indirections
