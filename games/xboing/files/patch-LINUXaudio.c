--- audio/LINUXaudio.c.orig	Fri Nov 22 02:28:33 1996
+++ audio/LINUXaudio.c	Tue Mar  4 22:06:01 2003
@@ -55,7 +55,7 @@
 #include <unistd.h>
 #include <stdio.h>
 #include <fcntl.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 
 #include "include/error.h"
 #include "include/audio.h"
@@ -78,7 +78,7 @@
  */
 
 static char				*Audio_dev = "/dev/audio";
-static int 				Audio_fd;
+static int 				Audio_fd = -1;
 /* size should depend on sample_rate */
 static unsigned char   	buf[BUFFER_SIZE];       
 static char 			errorString[255];
@@ -125,13 +125,14 @@
                   if (!strcmp(string, "EXIT"))
 	             {
                      /* Make sure that the audio device is flushed and reset */
+		     if ( Audio_fd >= 0 )
  	             ioctl(Audio_fd, SNDCTL_DSP_RESET, 0);
 
 		     exit(0); 
 	             }	
 
 	          /* Try to open the audio device */
- 	          if (!(Audio_fd = open(Audio_dev, O_WRONLY)))
+		  if ((Audio_fd = open(Audio_dev, O_WRONLY)) < 0)
   	          {	
 		         continue;
   	          }
@@ -185,6 +186,7 @@
                 /* Close the sound file */
                 (void) close(ifd);
 		(void) close(Audio_fd);
+		Audio_fd = -1;
              } while (True);
           }
        
