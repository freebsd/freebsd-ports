
$FreeBSD$

--- src/rio_add_song.c.orig	Sun Aug 22 16:53:27 2004
+++ src/rio_add_song.c	Sun Aug 22 16:55:17 2004
@@ -325,6 +325,7 @@
    send_command (rio_dev, 0x58, 0x0, card_number);
 
 try_next:
+   break;
    } /* end of add file loop */
 
    /* Close device */
@@ -624,7 +625,7 @@
          safe_strcat(display_string, "%", DISPLAY_STRING_LEN);
          break;
 
-        default:                                       /* No Action */
+        default: break;                                      /* No Action */
       }
 
     } else {
