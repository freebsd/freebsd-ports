
$FreeBSD$

--- mpg321.c.orig	Sun Mar 24 06:49:20 2002
+++ mpg321.c	Tue Aug 27 22:01:26 2002
@@ -509,9 +509,6 @@
 
         mad_decoder_finish(&decoder);
 
-        if (quit_now)
-            break;
-
         if (playbuf.frames)
              free(playbuf.frames);
 
@@ -521,6 +518,7 @@
         if (playbuf.fd == -1)
         {
             munmap(playbuf.buf, playbuf.length);
+            close(fd);
         }
 
         else
@@ -535,10 +533,6 @@
         ao_close(playdevice);
 
     ao_shutdown();
-
-#if defined(RAW_SUPPORT) || defined(HTTP_SUPPORT) || defined(FTP_SUPPORT) 
-    if(fd) close(fd);
-#endif
 
     return(0);
 }
