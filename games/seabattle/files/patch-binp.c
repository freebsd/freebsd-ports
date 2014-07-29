--- binp.c.orig	Wed May 14 02:51:00 1997
+++ binp.c	Fri Feb  2 04:22:56 2001
@@ -129,15 +129,15 @@
                                            /* Incomplete as of yet */
    if (which_one==1) 
       if (sound_device) 
-         if(rand()%2) system("cat hit1.au > /dev/audio ");
-         else system("cat hit2.au > /dev/audio ");
+         if(rand()%2) system("cat " DATADIR "/hit1.au > /dev/audio ");
+         else system("cat " DATADIR "/hit2.au > /dev/audio ");
       else beep();
    if (which_one==2)
       if (sound_device)
-         if(rand()%2) system("cat miss1.au > /dev/audio ");
-         else system("cat miss2.au > /dev/audio ");
+         if(rand()%2) system("cat " DATADIR "/miss1.au > /dev/audio ");
+         else system("cat " DATADIR "/miss2.au > /dev/audio ");
    if (which_one==3) 
-      if (sound_device) system("cat sunkit.au > /dev/audio ");
+      if (sound_device) system("cat " DATADIR "/sunkit.au > /dev/audio ");
       else beep();
 }
 
