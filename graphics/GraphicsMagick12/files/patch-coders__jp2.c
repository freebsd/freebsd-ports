--- ./coders/jp2.c.orig	2010-02-23 16:23:04.000000000 -0500
+++ ./coders/jp2.c	2010-02-23 16:23:24.000000000 -0500
@@ -681,7 +681,7 @@
 
   entry=SetMagickInfo("J2C");
   entry->description=AcquireString("JPEG-2000 Code Stream Syntax");
-  entry->module="JP2";
+  entry->module=AcquireString("JP2");
   entry->magick=(MagickHandler) IsJPC;
   entry->adjoin=False;
   entry->seekable_stream=True;
@@ -694,7 +694,7 @@
 
   entry=SetMagickInfo("JP2");
   entry->description=AcquireString("JPEG-2000 JP2 File Format Syntax");
-  entry->module="JP2";
+  entry->module=AcquireString("JP2");
   entry->magick=(MagickHandler) IsJP2;
   entry->adjoin=False;
   entry->seekable_stream=True;
@@ -707,7 +707,7 @@
 
   entry=SetMagickInfo("JPC");
   entry->description=AcquireString("JPEG-2000 Code Stream Syntax");
-  entry->module="JP2";
+  entry->module=AcquireString("JP2");
   entry->magick=(MagickHandler) IsJPC;
   entry->adjoin=False;
   entry->seekable_stream=True;
@@ -720,7 +720,7 @@
 
   entry=SetMagickInfo("PGX");
   entry->description=AcquireString("JPEG-2000 VM Format");
-  entry->module="JP2";
+  entry->module=AcquireString("JP2");
   entry->magick=(MagickHandler) IsJPC;
   entry->adjoin=False;
   entry->seekable_stream=True;
