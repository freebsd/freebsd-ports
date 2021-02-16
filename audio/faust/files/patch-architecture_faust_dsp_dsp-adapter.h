--- architecture/faust/dsp/dsp-adapter.h.orig	2021-02-16 21:19:00 UTC
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
 #include <iostream>
