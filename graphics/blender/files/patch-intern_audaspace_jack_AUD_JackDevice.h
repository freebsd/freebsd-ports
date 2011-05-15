--- intern/audaspace/jack/AUD_JackDevice..h.orig	2011-05-13 16:00:11.000000000 +0200
+++ intern/audaspace/jack/AUD_JackDevice.h	2011-05-13 16:00:34.000000000 +0200
@@ -38,8 +38,8 @@
 
 #include <string>
 
-#include <jack.h>
-#include <ringbuffer.h>
+#include <jack/jack.h>
+#include <jack/ringbuffer.h>
 
 typedef void (*AUD_syncFunction)(void*, int, float);
 
