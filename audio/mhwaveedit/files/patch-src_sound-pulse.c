--- src/sound-pulse.c.orig	2018-08-25 10:07:24 UTC
+++ src/sound-pulse.c
@@ -22,6 +22,8 @@
 #include <poll.h>
 #include <pulse/pulseaudio.h>
 
+#include "int_box.h"
+
 #ifndef PA_CHECK_VERSION
 #define PA_CHECK_VERSION(a,b,c) (0)
 #endif
