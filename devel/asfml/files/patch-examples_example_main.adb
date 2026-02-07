--- examples/example/main.adb.orig	2023-10-21 00:37:05 UTC
+++ examples/example/main.adb
@@ -41,7 +41,7 @@ begin
    setTexture(Sprite, Texture, sfTrue);
 
    -- Create a graphical text to display
-   Font := createFromFile("arial.ttf");
+   Font := createFromFile("%%PREFIX_FONTDIR%%webfonts/arial.ttf");
 
    Text := create;
    setString(Text, "Hello SFML");
