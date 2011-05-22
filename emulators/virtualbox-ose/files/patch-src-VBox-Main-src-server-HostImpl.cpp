--- src/VBox/Main/src-server/HostImpl.cpp.orig	2011-02-17 17:31:52.000000000 +0100
+++ src/VBox/Main/src-server/HostImpl.cpp	2011-02-17 23:46:50.000000000 +0100
@@ -249,6 +249,8 @@
 
     m->pParent = aParent;
 
+    HRESULT hrc = NULL;
+
 #ifdef VBOX_WITH_USB
     /*
      * Create and initialize the USB Proxy Service.
@@ -268,7 +270,7 @@
 # else
     m->pUSBProxyService = new USBProxyService(this);
 # endif
-    HRESULT hrc = m->pUSBProxyService->init();
+    hrc = m->pUSBProxyService->init();
     AssertComRCReturn(hrc, hrc);
 #endif /* VBOX_WITH_USB */
 
