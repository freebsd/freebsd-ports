--- Sources/Sound/Sound/ClanSound/oss.cpp.orig	Thu Jan 22 13:09:00 2004
+++ Sources/Sound/Sound/ClanSound/oss.cpp	Thu Jan 22 13:10:07 2004
@@ -28,6 +28,14 @@
 #include "API/Core/System/system.h"
 #include <Sound/Sound/ClanSound/oss.h>
 
+#ifndef AFMT_S16_NE
+#if defined(BYTE_ORDER) && (BYTE_ORDER == BIG_ENDIAN)
+#define AFMT_S16_NE AFMT_S16_BE
+#else
+#define AFMT_S16_NE AFMT_S16_LE
+#endif
+#endif
+
 // If USE_DRIVER_FRAGSIZE is defined, we use the fragsize (and number of them)
 // used by the soundcard driver. This is not as efficient as using our own
 // settings - mainly provided for debugging.
