--- sound.cc.orig	Wed Jun  7 22:41:06 2000
+++ sound.cc	Sat Sep  7 17:45:37 2002
@@ -39,7 +39,7 @@
 #include <linux/cdrom.h>
 //#include <linux/ucdrom.h>
 #else
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/cdio.h>
 #define CDROM_LEADOUT 0xAA
 #define CD_FRAMES 75 /* frames per second */
@@ -423,7 +423,7 @@
     }
   }
      
-  data = new short[NumSamples*2];  
+  data = new u_short[NumSamples*2];  
   memset((char*)data,0,NumSamples*4);
 }
 
