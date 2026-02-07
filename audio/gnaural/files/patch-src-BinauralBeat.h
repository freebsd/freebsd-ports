--- src/BinauralBeat.h.orig	2011-05-22 22:38:45 UTC
+++ src/BinauralBeat.h
@@ -166,7 +166,7 @@ int BB_SetupVoice (int VoiceID, // Array index for a B
                    int mute,    //TRUE or FALSE
                    int mono,    //TRUE or FALSE [added 20100614]
                    int NumberOfEvents); //how many events in your array
-void (*BB_UserFunc) (int voice);
+extern void (*BB_UserFunc) (int voice);
 void BB_Water (int voice, short *array, int arraylen, float Lowcut);
 short *BB_WaterInit (int arraylen, float pitch);
 void BB_WaterVoiceInit (int voice);
