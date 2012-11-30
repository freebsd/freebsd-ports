--- lib/gsimidi_pcm/instrument/patchgram.y.orig	2012-11-30 14:15:59.000000000 +0100
+++ lib/gsimidi_pcm/instrument/patchgram.y	2012-11-30 14:16:10.000000000 +0100
@@ -26,6 +26,7 @@
 
 %{
 #include <stdio.h>
+#include <stdlib.h>
 #include "../kpmidi.h"
 #include "../utils/log.h"
 #include "../midi_to_pcm.h"
