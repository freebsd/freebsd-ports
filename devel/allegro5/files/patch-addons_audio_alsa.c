--- addons/audio/alsa.c.orig	2020-02-10 02:03:00 UTC
+++ addons/audio/alsa.c
@@ -23,7 +23,7 @@
 #include "allegro5/allegro.h"
 #include "allegro5/internal/aintern_audio.h"
 
-#include <alloca.h>
+#include <stdlib.h>
 #include <alsa/asoundlib.h>
 
 ALLEGRO_DEBUG_CHANNEL("alsa")
