--- jfaudiolib/src/midi.c.orig	2024-03-06 07:31:42 UTC
+++ jfaudiolib/src/midi.c
@@ -35,7 +35,9 @@ Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 #ifdef _WIN32
 # include <malloc.h>
 #else
+#if !defined(__FreeBSD__)
 # include <alloca.h>
+#endif
 #endif
 #include "sndcards.h"
 #include "drivers.h"
