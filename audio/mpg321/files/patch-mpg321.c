
$FreeBSD$

--- mpg321.c.orig
+++ mpg321.c
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
@@ -285,6 +285,8 @@
         signal(SIGINT, SIG_DFL);
         
         playbuf.buf = NULL;
+        playbuf.frames = NULL;
+        playbuf.times = NULL;
         playbuf.fd = -1;
         playbuf.length = 0;
         playbuf.done = 0;
@@ -410,12 +412,14 @@
             
             if(fstat(fd, &stat) == -1)
             {
+                close(fd);
                 mpg321_error(currentfile);
                 continue;
             }
             
             if (!S_ISREG(stat.st_mode))
             {
+                close(fd);
                 continue;
             }
             
@@ -432,6 +436,7 @@
             if((playbuf.buf = mmap(0, playbuf.length, PROT_READ, MAP_SHARED, fd, 0))
                                 == MAP_FAILED)
             {
+                close(fd);
                 mpg321_error(currentfile);
                 continue;
             }
@@ -509,9 +514,6 @@
 
         mad_decoder_finish(&decoder);
 
-        if (quit_now)
-            break;
-
         if (playbuf.frames)
              free(playbuf.frames);
 
@@ -521,6 +523,7 @@
         if (playbuf.fd == -1)
         {
             munmap(playbuf.buf, playbuf.length);
+            close(fd);
         }
 
         else
@@ -535,10 +538,6 @@
         ao_close(playdevice);
 
     ao_shutdown();
-
-#if defined(RAW_SUPPORT) || defined(HTTP_SUPPORT) || defined(FTP_SUPPORT) 
-    if(fd) close(fd);
-#endif
 
     return(0);
 }
