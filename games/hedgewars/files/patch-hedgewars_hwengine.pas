--- hedgewars/hwengine.pas.orig	2025-07-22 17:12:55 UTC
+++ hedgewars/hwengine.pas
@@ -31,7 +31,7 @@
 
 uses {$IFDEF IPHONEOS}cmem, {$ENDIF} SDLh, uMisc, uConsole, uGame, uConsts, uLand, uAmmos, uVisualGears, uGears, uStore, uWorld, uInputHandler
      , uSound, uScript, uTeams, uStats, uIO, uLocale, uChat, uAI, uAIMisc, uAILandMarks, uLandTexture, uCollisions
-     , SysUtils, uTypes, uVariables, uCommands, uUtils, uCaptions, uDebug, uCommandHandlers, uLandPainted
+     , SysUtils, Math, uTypes, uVariables, uCommands, uUtils, uCaptions, uDebug, uCommandHandlers, uLandPainted
      , uPhysFSLayer, uCursor, uRandom, ArgParsers, uVisualGearsHandlers, uTextures, uRender
      {$IFDEF USE_VIDEO_RECORDING}, uVideoRec {$ENDIF}
      {$IFDEF USE_TOUCH_INTERFACE}, uTouch {$ENDIF}
@@ -678,6 +678,12 @@
 
     preInitEverything();
 
+{$IFNDEF PAS2C}
+    // C libraries such as Lua expect the FPU exceptions to be masked, as they are
+    // by default in C; Free Pascal enables some of them on PowerPC (and traps
+    // in lua_load on every numeric constant outside the int range otherwise).
+    SetExceptionMask([exInvalidOp, exDenormalized, exZeroDivide, exOverflow, exUnderflow, exPrecision]);
+{$ENDIF}
     GetParams();
 
     if GameType = gmtLandPreview then
