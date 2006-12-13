--- camlibs/canon/usb.c.orig	Sat Nov 25 15:47:24 2006
+++ camlibs/canon/usb.c	Wed Dec 13 09:28:25 2006
@@ -1308,6 +1308,7 @@
         int j, canon_subfunc = 0;
         char subcmd = 0, *subfunct_descr = "";
         int additional_read_bytes = 0;
+        char *msg;
 
         /* clear this to indicate that no data is there if we abort */
         if (return_length)
@@ -1546,7 +1547,7 @@
                 }
         }
 
-                char *msg = canon_usb_decode_status ( le32atoh ( buffer+0x50 ) );
+                msg = canon_usb_decode_status ( le32atoh ( buffer+0x50 ) );
                 if ( msg != NULL ) {
                         GP_DEBUG ( "canon_usb_dialogue_full: camera status \"%s\""
 				   " in response to command 0x%x 0x%x 0x%x (%s)",
