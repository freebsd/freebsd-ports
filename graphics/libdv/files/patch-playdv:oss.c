--- playdv/oss.c.orig	Sun Nov 18 21:50:24 2001
+++ playdv/oss.c	Sun Nov 18 21:53:48 2001
@@ -36,6 +36,19 @@
 
 #include "oss.h"
 
+#ifndef O_LARGEFILE
+# define O_LARGEFILE 0
+#endif
+
+#ifndef AFMT_S16_NE
+# include <machine/endian.h>
+# if BYTE_ORDER == LITTLE_ENDIAN
+#  define AFMT_S16_NE AFMT_S16_LE
+# else
+#  define AFMT_S16_NE AFMT_S16_BE
+# endif
+#endif
+
 static const char *default_device = "/dev/dsp";
 
 dv_oss_t *
