--- src/VBox/HostServices/SharedClipboard/x11-stub.cpp.orig	2017-10-18 07:12:48 UTC
+++ src/VBox/HostServices/SharedClipboard/x11-stub.cpp
@@ -55,7 +55,7 @@ void vboxClipboardDestroy (void)
 int vboxClipboardConnect (VBOXCLIPBOARDCLIENTDATA *pClient,
                           bool fHeadless)
 {
-    NOREF(pClient, fHeadless);
+    RT_NOREF2(pClient, fHeadless);
     LogFlowFunc(("called, returning VINF_SUCCESS.\n"));
     return VINF_SUCCESS;
 }
@@ -91,7 +91,7 @@ void vboxClipboardDisconnect (VBOXCLIPBOARDCLIENTDATA 
 void vboxClipboardFormatAnnounce (VBOXCLIPBOARDCLIENTDATA *pClient,
                                   uint32_t u32Formats)
 {
-    NOREF(pClient, u32Formats);
+    RT_NOREF2(pClient, u32Formats);
     LogFlowFunc(("called, returning.\n"));
 }
 
@@ -107,7 +107,7 @@ void vboxClipboardFormatAnnounce (VBOXCLIPBOARDCLIENTD
 int vboxClipboardReadData (VBOXCLIPBOARDCLIENTDATA *pClient, uint32_t u32Format,
                            void *pv, uint32_t cb, uint32_t *pcbActual)
 {
-    NOREF(pClient, u32Format, pv, cb);
+    RT_NOREF4(pClient, u32Format, pv, cb);
     LogFlowFunc(("called, returning VINF_SUCCESS.\n"));
     /* No data available. */
     *pcbActual = 0;
@@ -125,6 +125,6 @@ int vboxClipboardReadData (VBOXCLIPBOARDCLIENTDATA *pC
 void vboxClipboardWriteData (VBOXCLIPBOARDCLIENTDATA *pClient, void *pv,
                              uint32_t cb, uint32_t u32Format)
 {
-    NOREF(pClient, pv, cb, u32Format);
+    RT_NOREF4(pClient, pv, cb, u32Format);
     LogFlowFunc(("called, returning.\n"));
 }
