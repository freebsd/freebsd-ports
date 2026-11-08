--- examples/sound_spatial/main.adb.orig	2026-08-26 00:03:55 UTC
+++ examples/sound_spatial/main.adb
@@ -23,7 +23,7 @@ procedure Main is
    use type Sf.Audio.sfSoundBuffer_Ptr;
    use type Sf.Audio.sfSound_Ptr;
 
-   Buffer_Path : constant String := "../doodle_pop.ogg";
+   Buffer_Path : constant String := "%%DATADIR_AUDIO%%/doodle_pop.ogg";
    Buffer : Sf.Audio.sfSoundBuffer_Ptr := Sound_Buffer.createFromFile (Buffer_Path);
    The_Sound : Sf.Audio.sfSound_Ptr;
    Spatial_Cone : constant Cone.sfSoundSourceCone :=
