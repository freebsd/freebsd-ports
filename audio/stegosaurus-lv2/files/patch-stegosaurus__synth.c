--- stegosaurus_synth.c.orig	2020-09-19 18:50:38 UTC
+++ stegosaurus_synth.c
@@ -2,6 +2,8 @@
 #include "stegosaurus_synth.h"
 #include "noise.h"
 
+stegosaurus* stegosaurus_self = 0;
+
 voice* voices[4];
 int next_voice = 0;
 int keys[128];
