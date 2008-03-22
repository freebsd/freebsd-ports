--- src/libsphinxad/ad_oss_bsd.c        (revision 7548)
+++ src/libsphinxad/ad_oss_bsd.c        (working copy)
@@ -65,11 +65,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/ioctl.h>
-#if defined(SYS_SOUNDCARD_H)
 #include <sys/soundcard.h>
-#else
-#include <soundcard.h>
-#endif
 #include <errno.h>
 #include <config.h>

