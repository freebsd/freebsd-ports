
$FreeBSD$

--- mpg321.c.orig	Sun Mar 24 06:49:20 2002
+++ mpg321.c	Tue Sep  3 01:29:40 2002
@@ -188,7 +188,7 @@
             
             else
             {
-                printf(names[i]);
+                printf("%s", names[i]);
                 free(names[i]);
             }
         }
@@ -203,7 +203,7 @@
             if (!names[i])  {
                 fprintf (stderr, emptystring);
             }   else    {
-                fprintf (stderr, names[i]);
+                fprintf (stderr, "%s", names[i]);
                 free (names[i]);
             }
             if (i%2) fprintf (stderr, "\n");
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
