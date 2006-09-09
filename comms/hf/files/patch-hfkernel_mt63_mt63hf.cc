--- hfkernel/mt63/mt63hf.cc.orig	Sun Jul 30 11:43:28 2006
+++ hfkernel/mt63/mt63hf.cc	Sun Jul 30 11:44:07 2006
@@ -35,6 +35,10 @@
 #include <errno.h>
 #include <ctype.h>
 
+#ifdef __FreeBSD__ 
+#include <unistd.h>
+#endif
+
 #include "dsp.h"
 #include "mt63.h"
 #include "sound.h"
