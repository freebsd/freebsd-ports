--- architecture/faust/dsp/dsp-adapter.h.orig	2024-12-26 11:33:55 UTC
+++ architecture/faust/dsp/dsp-adapter.h
@@ -26,7 +26,11 @@
 #define __dsp_adapter__
 
 #ifndef _WIN32
-#include <alloca.h>
+#  ifndef __FreeBSD__
+#    include <alloca.h>
+#  else
+#    include <stdlib.h>
+#  endif
 #endif
 #include <string.h>
 #include <cmath>
