--- src/portaudiobackend.c.orig	2012-09-20 22:44:28.823018000 +0900
+++ src/portaudiobackend.c	2012-10-05 06:05:30.000000000 +0900
@@ -16,6 +16,7 @@
 #include "portaudioutil.h"
 #include "midi.h"
 #include "fluid.h"
+#include "audiointerface.h"
 
 #include <portaudio.h>
 #include <glib.h>
