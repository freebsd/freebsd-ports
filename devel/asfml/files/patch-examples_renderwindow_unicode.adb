--- examples/renderwindow/unicode.adb.orig	2026-08-26 00:13:05 UTC
+++ examples/renderwindow/unicode.adb
@@ -35,13 +35,13 @@ begin
 
 begin
 
-   Img := CreateFromFile ("../../images/ASFML_Logo.png");
+   Img := CreateFromFile ("%%DATADIR_IMAGES%%/ASFML_Logo.png");
    if Img = null then
       Put_Line ("Could not open image");
       return;
    end if;
 
-   Icon := CreateFromFile ("../../images/sfml-icon.png");
+   Icon := CreateFromFile ("%%DATADIR_IMAGES%%/sfml-icon.png");
    if Icon = null then
       Put_Line ("Could not open icon");
       Destroy (Img);
@@ -59,7 +59,7 @@ begin
       (x => Float (sfUint32 (Mode.size.x) / 2 - GetSize (Img).x / 2),
        y => Float (sfUint32 (Mode.size.y) / 2 - GetSize (Img).y / 2)));
 
-   Font := CreateFromFile("DejaVuSans.ttf");
+   Font := CreateFromFile("%%FONTSDIR%%/DejaVuSans.ttf");
    if Font = null then
       Put_Line ("Could not get font");
       Destroy (Sprite);
