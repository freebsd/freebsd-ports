--- ofc/DPNGImage.m.orig	2008-08-20 17:16:29 UTC
+++ ofc/DPNGImage.m
@@ -346,7 +346,7 @@ static void _warning(png_structp png, pn
     
     if (ok)
     {
-      if (setjmp(png->jmpbuf))
+      if (setjmp(png_jmpbuf(png)))
       {
         WARNING(DW_UNKNOWN_WARNING, "Error reading PNG file");
         ok     = NO;
@@ -406,7 +406,7 @@ static void _warning(png_structp png, pn
       
       _width  = (unsigned) width;
       _height = (unsigned) height;
-      _bpp    = info->channels;
+      _bpp    = png_get_channels(png, info);
       _images = 1;
       
       _reading = YES;
@@ -485,7 +485,7 @@ static void _warning(png_structp png, pn
     
     if (ok)
     {
-      if (setjmp(png->jmpbuf))
+      if (setjmp(png_jmpbuf(png)))
       {
         WARNING(DW_UNKNOWN_WARNING, "Error writing PNG file");
         ok     = NO;
@@ -553,7 +553,7 @@ static void _warning(png_structp png, pn
     
     pixels = _width;
     
-    if (setjmp(png->jmpbuf))
+    if (setjmp(png_jmpbuf(png)))
     {
       WARNING(DW_UNKNOWN_WARNING, "Error reading PNG file");
       pixels = 0;
@@ -599,7 +599,7 @@ static void _warning(png_structp png, pn
     
     png_structp png = (png_structp) _png;
     
-    if (setjmp(png->jmpbuf))
+    if (setjmp(png_jmpbuf(png)))
     {
       WARNING(DW_UNKNOWN_WARNING, "Error writing PNG file");
       ok     = NO;
