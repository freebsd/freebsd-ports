--- mix.h.orig	2003-10-14 22:02:58 UTC
+++ mix.h
@@ -4,7 +4,7 @@
 #include "pce.h"
 #include "sound.h"
 
-void (*update_sound[4])();
+extern void (*update_sound[4])();
 
 UInt32 WriteBufferAdpcm8(UChar *buf,
                        UInt32 begin,
