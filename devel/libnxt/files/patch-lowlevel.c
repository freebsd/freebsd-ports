--- lowlevel.c.orig	Sat May  5 16:14:13 2007
+++ lowlevel.c	Sat May  5 16:14:37 2007
@@ -103,7 +103,7 @@
       return NXT_CONFIGURATION_ERROR;
     }
 
-  ret = usb_claim_interface(nxt->hdl, 1);
+  ret = usb_claim_interface(nxt->hdl, 0);
   if (ret < 0)
     {
       usb_close(nxt->hdl);
@@ -115,7 +115,7 @@
   nxt_recv_buf(nxt, buf, 2);
   if (memcmp(buf, "\n\r", 2) != 0)
     {
-      usb_release_interface(nxt->hdl, 1);
+      usb_release_interface(nxt->hdl, 0);
       usb_close(nxt->hdl);
       return NXT_HANDSHAKE_FAILED;
     }
@@ -127,7 +127,7 @@
 nxt_error_t
 nxt_close(nxt_t *nxt)
 {
-  usb_release_interface(nxt->hdl, 1);
+  usb_release_interface(nxt->hdl, 0);
   usb_close(nxt->hdl);
   free(nxt);
 
