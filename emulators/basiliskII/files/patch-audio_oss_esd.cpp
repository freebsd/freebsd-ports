
$FreeBSD$

--- audio_oss_esd.cpp	2003/01/06 16:41:21	1.1
+++ audio_oss_esd.cpp	2003/01/06 16:41:34
@@ -31,7 +31,7 @@
 #endif
 
 #ifdef __FreeBSD__
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif
 
 #include "cpu_emulation.h"
