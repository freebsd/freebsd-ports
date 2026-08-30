--- examples/example/main.adb.orig	2026-08-26 00:17:49 UTC
+++ examples/example/main.adb
@@ -41,7 +41,7 @@ Resources: begin
       Window := create(Mode, "SFML window");
 
       -- Load a sprite to display
-      Texture := createFromFile("../../images/ASFML_Logo.png");
+      Texture := createFromFile("%%DATADIR_IMAGES%%/ASFML_Logo.png");
 
       if Texture = null then
          raise Resource_Unavailable;
@@ -51,7 +51,7 @@ Resources: begin
       setPosition(Sprite, (x => 200.0, y => 200.0));
 
       -- Create a graphical text to display
-      Font := createFromFile("../tuffy.ttf");
+      Font := createFromFile("%%FONTSDIR%%/tuffy.ttf");
 
       if Font = null then
          raise Resource_Unavailable;
@@ -63,7 +63,7 @@ Resources: begin
       setCharacterSize(Text, 50);
 
       -- Load a music file to play
-      Music := createFromFile("../doodle_pop.ogg");
+      Music := createFromFile("%%DATADIR_AUDIO%%/doodle_pop.ogg");
 
       if Music = null then
          raise Resource_Unavailable;
