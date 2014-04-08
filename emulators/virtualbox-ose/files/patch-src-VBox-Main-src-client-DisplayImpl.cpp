--- src/VBox/Main/src-client/DisplayImpl.cpp.orig	2014-03-26 15:19:05.000000000 -0400
+++ src/VBox/Main/src-client/DisplayImpl.cpp	2014-04-02 17:42:48.000000000 -0400
@@ -4382,6 +4382,7 @@
 }
 #endif
 
+#if defined(VBOX_WITH_HGCM) && defined(VBOX_WITH_CROGL)
 DECLCALLBACK(void)  Display::displayCrHgcmCtlSubmitCompletion(int32_t result, uint32_t u32Function, PVBOXHGCMSVCPARM pParam, void *pvContext)
 {
     VBOXCRCMDCTL *pCmd = (VBOXCRCMDCTL*)pParam->u.pointer.addr;
@@ -4424,7 +4425,6 @@
     return pThis->handleCrHgcmCtlSubmit(pCmd, cbCmd, pfnCompletion, pvCompletion);
 }
 
-#if defined(VBOX_WITH_HGCM) && defined(VBOX_WITH_CROGL)
 DECLCALLBACK(void)  Display::displayCrAsyncCmdCompletion(int32_t result, uint32_t u32Function, PVBOXHGCMSVCPARM pParam, void *pvContext)
 {
     Display *pDisplay = (Display *)pvContext;
@@ -5050,7 +5050,9 @@
     pThis->IConnector.pfnCrHgsmiCommandProcess = Display::displayCrHgsmiCommandProcess;
     pThis->IConnector.pfnCrHgsmiControlProcess = Display::displayCrHgsmiControlProcess;
 #endif
+#if defined(VBOX_WITH_HGCM) && defined(VBOX_WITH_CROGL)
     pThis->IConnector.pfnCrHgcmCtlSubmit       = Display::displayCrHgcmCtlSubmit;
+#endif
 #ifdef VBOX_WITH_HGSMI
     pThis->IConnector.pfnVBVAEnable            = Display::displayVBVAEnable;
     pThis->IConnector.pfnVBVADisable           = Display::displayVBVADisable;
