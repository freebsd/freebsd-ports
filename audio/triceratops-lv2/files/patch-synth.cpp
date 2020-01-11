--- synth.cpp.orig	2019-04-11 12:27:29 UTC
+++ synth.cpp
@@ -1,5 +1,7 @@
 
-
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include "synth.h"
 
 // CONSTRUCTOR
