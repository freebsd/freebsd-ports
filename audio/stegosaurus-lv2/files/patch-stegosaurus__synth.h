--- stegosaurus_synth.h.orig	2020-09-19 18:50:03 UTC
+++ stegosaurus_synth.h
@@ -26,7 +26,7 @@ void stegosaurus_synth_set_osc_waves(int, int, int);
 #define ENV_STATE_KILL 7
 
 
-stegosaurus* stegosaurus_self;
+extern stegosaurus* stegosaurus_self;
 
 
 	typedef struct
