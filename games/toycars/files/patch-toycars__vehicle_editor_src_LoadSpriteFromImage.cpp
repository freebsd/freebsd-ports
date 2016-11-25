--- toycars_vehicle_editor/src/LoadSpriteFromImage.cpp.orig	2009-02-26 19:24:22 UTC
+++ toycars_vehicle_editor/src/LoadSpriteFromImage.cpp
@@ -23,7 +23,7 @@
 //{jpg,png,bmp,pnm,pbm,pgm,ppm}
 Fl_Image* loadImage(const char *filename)
 {
-   char *suffix = strrchr(filename, '.');
+   const char *suffix = strrchr(filename, '.');
    if (suffix == NULL)
       return NULL;
    if (strcmp(suffix,".jpg") == 0)
