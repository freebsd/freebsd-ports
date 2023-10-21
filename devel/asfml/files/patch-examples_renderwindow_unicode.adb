--- examples/renderwindow/unicode.adb.orig	2023-10-21 00:41:27 UTC
+++ examples/renderwindow/unicode.adb
@@ -35,13 +35,13 @@ begin
 
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
@@ -59,7 +59,7 @@ begin
                          (x => Float (sfUint32 (Mode.Width) / 2 - GetSize (Img).x / 2),
                           y => Float (sfUint32 (Mode.Height) / 2 - GetSize (Img).y / 2)));
 
-   Font := CreateFromFile("DejaVuSans.ttf");
+   Font := CreateFromFile("%%PREFIX_FONTDIR%%dejavu/DejaVuSans.ttf");
    if Font = null then
       Put_Line ("Could not get font");
       Destroy (Sprite);
