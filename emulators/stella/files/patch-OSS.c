--- src/ui/sound/OSS.c.orig	Tue Jan  8 17:11:32 2002
+++ src/ui/sound/OSS.c	Mon Dec 30 04:08:03 2002
@@ -32,12 +32,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <string.h>
-
-#ifdef __FreeBSD__
-  #include <machine/soundcard.h>
-#else
-  #include <sys/soundcard.h>
-#endif
+#include <sys/soundcard.h>
 
 #include "TIASound.h"
