--- user-twpsk/twpsk.C.orig	Mon May  2 20:19:50 2005
+++ user-twpsk/twpsk.C	Mon May  2 20:20:17 2005
@@ -368,10 +368,12 @@
       }  
 
       val = 0;  // no input sigs get to output
+/*
       if (ioctl(mixer_fd, MIXER_WRITE(SOUND_MIXER_OUTSRC), &val) < 0)
       {
          fprintf (stderr, "mixer outsrc failed\n");
       }
+*/
       close (mixer_fd);
    }
    else
