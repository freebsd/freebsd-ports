--- ./src/snd.c.orig	Thu May 29 22:03:20 2003
+++ ./src/snd.c	Thu May 29 22:17:00 2003
@@ -9,7 +9,14 @@
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <endian.h>
+#if HAVE_SYS_BYTEORDER_H
+# include <sys/byteorder.h>
+#elif HAVE_MACHINE_ENDIAN_H
+# include <machine/endian.h>
+#elif HAVE_ENDIAN_H
+# include <endian.h>
+#endif
+
 #include <sys/soundcard.h>
 #include <sys/ioctl.h>
 
@@ -18,6 +25,8 @@
 #include "misc.h"
 
 #undef SND_DEBUG
+
+#define AFMT_S16_NE AFMT_S16_LE
 
 /* ---------------------------------------------------------------------- */
 
