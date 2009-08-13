--- magick/fourier.c.orig	2009-08-13 09:03:13.924505718 +0200
+++ magick/fourier.c	2009-08-13 09:03:24.685881339 +0200
@@ -515,7 +515,7 @@
       for (x=0L; x < (long) fourier_info->center; x++)
       {
         magnitude[i]=cabs(fourier[i]);
-        phase[i]=carg(fourier[i]);
+        phase[i]=atan2(cimag(fourier[i]),creal(fourier[i]));
         i++;
       }
   else
