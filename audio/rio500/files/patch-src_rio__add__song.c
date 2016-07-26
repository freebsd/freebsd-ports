--- src/rio_add_song.c.orig	2000-06-14 13:46:06 UTC
+++ src/rio_add_song.c
@@ -325,6 +325,7 @@ main(int argc, char *argv[])
    send_command (rio_dev, 0x58, 0x0, card_number);
 
 try_next:
+   break;
    } /* end of add file loop */
 
    /* Close device */
@@ -624,7 +625,7 @@ printf("%s\n", display_format);
          safe_strcat(display_string, "%", DISPLAY_STRING_LEN);
          break;
 
-        default:                                       /* No Action */
+        default: break;                                      /* No Action */
       }
 
     } else {
