--- src/slv_link.c.orig	Wed Aug 27 11:34:38 2003
+++ src/slv_link.c	Tue Mar 23 16:09:02 2004
@@ -1423,6 +1423,7 @@
      MAX_PACKET_SIZE, (time_out * 10));
    */
 
+#ifndef __BSD__
   /* Reset endpoints */
   ret = usb_clear_halt(tigl_han, TIGL_BULK_OUT);
   if (ret < 0) {
@@ -1455,6 +1456,7 @@
       }
     }
   }
+#endif
 
   /* Reset buffers */
   nBytesRead = 0;
