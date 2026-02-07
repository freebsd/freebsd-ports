--- examples/pong/pong.adb.orig	2023-10-21 00:38:34 UTC
+++ examples/pong/pong.adb
@@ -42,7 +42,7 @@ begin
    Reset (Gen);
    Win := RenderWindow.Create(mode => (GameWidth, GameHeight, 32), title => "Ada SFML Pong");
    RenderWindow.SetVerticalSyncEnabled(Win, sfTrue);
-   BallSoundBuffer := SoundBuffer.CreateFromFile("ping_pong_8bit_beeep.ogg");
+   BallSoundBuffer := SoundBuffer.CreateFromFile("%%DATA_AUDIO%%ping_pong_8bit_beeep.ogg");
    BallSound := Sound.Create;
    Sound.SetBuffer(BallSound, BallSoundBuffer);
    LeftPaddle := RectangleShape.Create;
@@ -65,7 +65,7 @@ begin
    CircleShape.setOutlineColor (Ball, Color.sfBlack);
    CircleShape.setFillColor (Ball, Color.sfWhite);
    CircleShape.setOrigin (Ball, (0.5 * BallRadius, 0.5 * BallRadius));
-   GameFont := Font.CreateFromFile("../renderwindow/aerial.ttf");
+   GameFont := Font.CreateFromFile("%%DATA_FONTS%%aerial.ttf");
    GameMessage := Text.Create;
    Text.setFont (GameMessage, GameFont);
    Text.setCharacterSize (GameMessage, 30);
