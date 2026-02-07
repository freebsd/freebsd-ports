--- src/pyParser.h.orig	2019-04-09 08:24:03 UTC
+++ src/pyParser.h
@@ -11,6 +11,10 @@
 
 #include "py.h"
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
+
 #define PY_SEPERATOR '\''
 #define PY_SEPERATOR_S "'"
 
