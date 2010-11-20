--- pdf-backend.cc.orig	2010-10-31 16:26:02.000000000 +0100
+++ pdf-backend.cc	2010-10-31 16:27:10.000000000 +0100
@@ -99,7 +99,7 @@
   return html_color(rgb);
 }
 
-static void cmyk_to_rgb(double cmyk[], double rgb[])
+static void cmyk_to_rgb(const double cmyk[], double rgb[])
 {
   static pdf::gfx::DeviceCmykColorSpace cmyk_space;
   pdf::gfx::Color cmyk_cc;
@@ -124,7 +124,7 @@
     border_colors.push_back("");
     return true;
   }
-  double *values = color->getValues();
+  const double *values = color->getValues();
   switch (color->getSpace())
   {
   case pdf::ant::Color::colorTransparent:
