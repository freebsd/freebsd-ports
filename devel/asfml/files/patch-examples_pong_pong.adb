--- examples/pong/pong.adb.orig	2026-08-26 00:15:15 UTC
+++ examples/pong/pong.adb
@@ -44,7 +44,7 @@ begin
       (mode => (size => (GameWidth, GameHeight), bitsPerPixel => 32),
        title => "Ada SFML Pong");
    RenderWindow.SetVerticalSyncEnabled(Win, sfTrue);
-   BallSoundBuffer := SoundBuffer.CreateFromFile("ping_pong_8bit_beeep.ogg");
+   BallSoundBuffer := SoundBuffer.CreateFromFile("%%DATADIR_AUDIO%%/ping_pong_8bit_beeep.ogg");
    BallSound := Sound.Create (BallSoundBuffer);
    LeftPaddle := RectangleShape.Create;
 
@@ -66,7 +66,7 @@ begin
    CircleShape.setOutlineColor (Ball, Color.sfBlack);
    CircleShape.setFillColor (Ball, Color.sfWhite);
    CircleShape.setOrigin (Ball, (0.5 * BallRadius, 0.5 * BallRadius));
-   GameFont := Font.CreateFromFile("../renderwindow/aerial.ttf");
+   GameFont := Font.CreateFromFile("%%FONTSDIR%%/aerial.ttf");
    GameMessage := Text.Create;
    Text.setFont (GameMessage, GameFont);
    Text.setCharacterSize (GameMessage, 30);
