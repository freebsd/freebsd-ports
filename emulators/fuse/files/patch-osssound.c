--- sound/osssound.c.orig	Sat Sep 13 16:53:12 2003
+++ sound/osssound.c	Tue Oct 28 17:19:06 2003
@@ -107,6 +107,7 @@
   return 1;
   }
 
+#if 0
 if(*freqptr>8250) frag++;
 if(*freqptr>16500) frag++;
 if(*freqptr>33000) frag++;
@@ -118,6 +119,7 @@
   close(soundfd);
   return 1;
   }
+#endif
 
 return 0;	/* success */
 }
