$FreeBSD$

--- LINUXaudio.c.orig	Sun Jul 14 16:03:01 2002
+++ LINUXaudio.c	Sun Jul 14 16:02:48 2002
@@ -89,6 +89,7 @@ void setsndparms( int dspfd, int format,
     warning(errmsg);
   }
 
+#ifndef __FreeBSD__
   /* set DMA buffer fragment size to Csound's output buffer size */
   parm = 0; frag_size = 1;
   /* find least power of 2 >= bufsiz */
@@ -101,7 +102,6 @@ void setsndparms( int dspfd, int format,
   if (ioctl(dspfd, SNDCTL_DSP_SETFRAGMENT, &parm) == -1)
     die(Str(X_755,"failed while trying to set soundcard DMA buffer size"));
 
-#ifndef FREE_BSD
   /* find out what buffer size the driver allocated */
   if (ioctl(dspfd, SNDCTL_DSP_GETBLKSIZE, &parm) == -1)
     die(Str(X_754,"failed while querying soundcard about buffer size"));
