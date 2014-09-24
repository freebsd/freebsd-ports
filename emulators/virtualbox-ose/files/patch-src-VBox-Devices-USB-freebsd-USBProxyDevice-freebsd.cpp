--- src/VBox/Devices/USB/freebsd/USBProxyDevice-freebsd.cpp.orig	2014-09-09 23:54:12.000000000 +0400
+++ src/VBox/Devices/USB/freebsd/USBProxyDevice-freebsd.cpp	2014-09-11 00:40:37.313435496 +0400
@@ -52,6 +52,7 @@
 #include <iprt/asm.h>
 #include <iprt/string.h>
 #include <iprt/file.h>
+#include <iprt/pipe.h>
 #include "../USBProxyDevice.h"
 
 /** Maximum endpoints supported. */
@@ -95,12 +96,16 @@
 {
     /** The open file. */
     RTFILE                 hFile;
-    /** Software endpoint structures */
-    USBENDPOINTFBSD        aSwEndpoint[USBFBSD_MAXENDPOINTS];
     /** Flag whether an URB is cancelling. */
     bool                   fCancelling;
     /** Flag whether initialised or not */
     bool                   fInit;
+    /** Pipe handle for waiking up - writing end. */
+    RTPIPE                 hPipeWakeupW;
+    /** Pipe handle for waiking up - reading end. */
+    RTPIPE                 hPipeWakeupR;
+    /** Software endpoint structures */
+    USBENDPOINTFBSD        aSwEndpoint[USBFBSD_MAXENDPOINTS];
     /** Kernel endpoint structures */
     struct usb_fs_endpoint aHwEndpoint[USBFBSD_MAXENDPOINTS];
 } USBPROXYDEVFBSD, *PUSBPROXYDEVFBSD;
@@ -453,7 +458,6 @@
     pDevFBSD->hFile = NIL_RTFILE;
 
     RTMemFree(pDevFBSD);
-    pProxyDev->Backend.pv = NULL;
 
     LogFlow(("usbProxyFreeBSDClose: returns\n"));
 }
@@ -984,6 +988,16 @@
     return usbProxyFreeBSDEndpointClose(pProxyDev, index);
 }
 
+static DECLCALLBACK(int) usbProxyFreeBSDWakeup(PUSBPROXYDEV pProxyDev)
+{
+    PUSBPROXYDEVFBSD pDevFBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVFBSD);
+    size_t cbIgnored;
+
+    LogFlowFunc(("pProxyDev=%p\n", pProxyDev));
+
+    return RTPipeWrite(pDevFBSD->hPipeWakeupW, "", 1, &cbIgnored);
+}
+
 /**
  * The FreeBSD USB Proxy Backend.
  */
@@ -1005,6 +1019,7 @@
     usbProxyFreeBSDUrbQueue,
     usbProxyFreeBSDUrbCancel,
     usbProxyFreeBSDUrbReap,
+    usbProxyFreeBSDWakeup,
     0
 };
 
