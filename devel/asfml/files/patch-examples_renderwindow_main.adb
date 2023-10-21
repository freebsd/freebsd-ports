--- examples/renderwindow/main.adb.orig	2023-10-21 00:40:13 UTC
+++ examples/renderwindow/main.adb
@@ -33,13 +33,13 @@ begin
 
 begin
 
-   Img := CreateFromFile ("logo.png");
+   Img := CreateFromFile ("%%DATA_GRAPHICS%%logo.png");
    if Img = null then
       Put_Line ("Could not open image");
       return;
    end if;
 
-   Icon := CreateFromFile ("sfml-icon.png");
+   Icon := CreateFromFile ("%%DATA_GRAPHICS%%sfml-icon.png");
    if Icon = null then
       Put_Line ("Could not open icon");
       Destroy (Img);
@@ -58,7 +58,7 @@ begin
                           y => Float (sfUint32 (Mode.Height) / 2 - GetSize (Img).y / 2)));
    --sfSprite_SetBlendMode (Sprite, sfBlendAlpha);
 
-   Font := CreateFromFile("aerial.ttf");
+   Font := CreateFromFile("%%DATA_FONTS%%aerial.ttf");
    if Font = null then
       Put_Line ("Could not get font");
       Destroy (Sprite);
