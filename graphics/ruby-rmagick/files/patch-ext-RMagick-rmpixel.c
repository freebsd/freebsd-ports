--- ext/RMagick/rmpixel.c.orig	2010-03-29 09:50:48.192772200 +0200
+++ ext/RMagick/rmpixel.c	2010-03-29 09:52:23.334284319 +0200
@@ -531,7 +531,7 @@
     // Ugly way of checking for change in ImageMagick 6.5.6-5 to see whether
     // saturation/lightness should be out of 255 or out of 100.
     if(MagickLibVersion < 0x656 ||
-        (MagickLibVersion == 0x656 && strcmp(MagickLibSubversion,"-5") <= 0) )
+        (MagickLibVersion == 0x656 && strcmp(MagickLibAddendum,"-5") <= 0) )
     {
       s = s/2.55;
       l = l/2.55;
