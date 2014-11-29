--- src/VBox/Devices/USB/freebsd/USBProxyDevice-freebsd.cpp.orig	2014-10-11 08:06:56.000000000 -0400
+++ src/VBox/Devices/USB/freebsd/USBProxyDevice-freebsd.cpp	2014-11-18 15:10:55.000000000 -0500
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
+    /** Pipe handle for waking up - writing end. */
+    RTPIPE                 hPipeWakeupW;
+    /** Pipe handle for waking up - reading end. */
+    RTPIPE                 hPipeWakeupR;
+    /** Software endpoint structures */
+    USBENDPOINTFBSD        aSwEndpoint[USBFBSD_MAXENDPOINTS];
     /** Kernel endpoint structures */
     struct usb_fs_endpoint aHwEndpoint[USBFBSD_MAXENDPOINTS];
 } USBPROXYDEVFBSD, *PUSBPROXYDEVFBSD;
@@ -383,10 +388,17 @@
         rc = usbProxyFreeBSDFsInit(pProxyDev);
         if (RT_SUCCESS(rc))
         {
-            LogFlow(("usbProxyFreeBSDOpen(%p, %s): returns successfully hFile=%RTfile iActiveCfg=%d\n",
-                     pProxyDev, pszAddress, pDevFBSD->hFile, pProxyDev->iActiveCfg));
+            /*
+             * Create wakeup pipe.
+             */
+            rc = RTPipeCreate(&pDevFBSD->hPipeWakeupR, &pDevFBSD->hPipeWakeupW, 0);
+            if (RT_SUCCESS(rc))
+            {
+                LogFlow(("usbProxyFreeBSDOpen(%p, %s): returns successfully hFile=%RTfile iActiveCfg=%d\n",
+                         pProxyDev, pszAddress, pDevFBSD->hFile, pProxyDev->iActiveCfg));
 
-            return VINF_SUCCESS;
+                return VINF_SUCCESS;
+            }
         }
 
         RTFileClose(hFile);
@@ -449,11 +461,13 @@
 
     usbProxyFreeBSDFsUnInit(pProxyDev);
 
+    RTPipeClose(pDevFBSD->hPipeWakeupR);
+    RTPipeClose(pDevFBSD->hPipeWakeupW);
+
     RTFileClose(pDevFBSD->hFile);
     pDevFBSD->hFile = NIL_RTFILE;
 
     RTMemFree(pDevFBSD);
-    pProxyDev->Backend.pv = NULL;
 
     LogFlow(("usbProxyFreeBSDClose: returns\n"));
 }
@@ -822,7 +836,7 @@
     PUSBENDPOINTFBSD pEndpointFBSD;
     PVUSBURB pUrb;
     struct usb_fs_complete UsbFsComplete;
-    struct pollfd PollFd;
+    struct pollfd pfd[2];
     int rc;
 
     LogFlow(("usbProxyFreeBSDUrbReap: pProxyDev=%p, cMillies=%u\n",
@@ -948,21 +962,34 @@
     }
     else if (cMillies && rc == VERR_RESOURCE_BUSY)
     {
-        /* Poll for finished transfers */
-        PollFd.fd = RTFileToNative(pDevFBSD->hFile);
-        PollFd.events = POLLIN | POLLRDNORM;
-        PollFd.revents = 0;
-
-        rc = poll(&PollFd, 1, (cMillies == RT_INDEFINITE_WAIT) ? INFTIM : cMillies);
-        if (rc >= 1)
-        {
-            goto repeat;
-        }
-        else
+        for (;;)
         {
-            LogFlow(("usbProxyFreeBSDUrbReap: "
-                     "poll returned rc=%d\n", rc));
+            pfd[0].fd = RTFileToNative(pDevFBSD->hFile);
+            pfd[0].events = POLLIN | POLLRDNORM;
+            pfd[0].revents = 0;
+
+            pfd[1].fd = RTPipeToNative(pDevFBSD->hPipeWakeupR);
+            pfd[1].events = POLLIN | POLLRDNORM;
+            pfd[1].revents = 0;
+
+            rc = poll(pfd, 2, (cMillies == RT_INDEFINITE_WAIT) ? INFTIM : cMillies);
+            if (rc > 0)
+            {
+                if (pfd[1].revents & POLLIN)
+                {
+                    /* Got woken up, drain pipe. */
+                    uint8_t bRead;
+                    size_t cbIgnored = 0;
+                    RTPipeRead(pDevFBSD->hPipeWakeupR, &bRead, 1, &cbIgnored);
+                }
+                break;
+            }
+            if (rc == 0)
+                return NULL;
+            if (errno != EAGAIN)
+                return NULL;
         }
+        goto repeat;
     }
     return pUrb;
 }
@@ -984,6 +1011,16 @@
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
@@ -1005,6 +1042,7 @@
     usbProxyFreeBSDUrbQueue,
     usbProxyFreeBSDUrbCancel,
     usbProxyFreeBSDUrbReap,
+    usbProxyFreeBSDWakeup,
     0
 };
 
