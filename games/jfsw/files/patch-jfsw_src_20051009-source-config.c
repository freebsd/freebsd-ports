--- jfsw_src_20051009/source/config.c.orig	2005-10-09 15:28:26.000000000 +0200
+++ jfsw_src_20051009/source/config.c	2005-10-10 15:02:08.000000000 +0200
@@ -63,8 +63,8 @@
 //
 // Sound variables
 //
-int32 FXDevice    = -1;
-int32 MusicDevice = -1;
+int32 FXDevice    = 1;
+int32 MusicDevice = 1;
 int32 FXVolume    = 192;
 int32 MusicVolume = 128;
 int32 NumVoices   = 4;
@@ -215,8 +215,8 @@
    ScreenWidth = 640;
    ScreenHeight = 480;
    ScreenBPP = 8;
-   FXDevice = -1;
-   MusicDevice = -1;
+   FXDevice = 1;
+   MusicDevice = 1;
    FXVolume = 192;
    MusicVolume = 128;
    NumVoices = 4;
