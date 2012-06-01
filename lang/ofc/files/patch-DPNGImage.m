--- ofc/DPNGImage.m.orig	2008-08-20 19:16:29.000000000 +0200
+++ ofc/DPNGImage.m	2012-05-09 13:07:56.000000000 +0200
@@ -30,6 +30,7 @@
 
 #ifdef HAVE_DPNGIMAGE
 #include "png.h"
+#include "pngpriv.h"
 #endif
 
 
@@ -346,7 +347,7 @@
     
     if (ok)
     {
-      if (setjmp(png->jmpbuf))
+      if (setjmp(png_jmpbuf(png)))
       {
         WARNING(DW_UNKNOWN_WARNING, "Error reading PNG file");
         ok     = NO;
@@ -485,7 +486,7 @@
     
     if (ok)
     {
-      if (setjmp(png->jmpbuf))
+      if (setjmp(png_jmpbuf(png)))
       {
         WARNING(DW_UNKNOWN_WARNING, "Error writing PNG file");
         ok     = NO;
@@ -553,7 +554,7 @@
     
     pixels = _width;
     
-    if (setjmp(png->jmpbuf))
+    if (setjmp(png_jmpbuf(png)))
     {
       WARNING(DW_UNKNOWN_WARNING, "Error reading PNG file");
       pixels = 0;
@@ -599,7 +600,7 @@
     
     png_structp png = (png_structp) _png;
     
-    if (setjmp(png->jmpbuf))
+    if (setjmp(png_jmpbuf(png)))
     {
       WARNING(DW_UNKNOWN_WARNING, "Error writing PNG file");
       ok     = NO;
