--- /usr/ports/emulators/pearpc/work/pearpc-0.1.2/src/io/3c90x/3c90x.cc	Thu May 20 18:00:21 2004
+++ src/io/3c90x/3c90x.cc	Sat May 22 13:56:19 2004
@@ -47,6 +47,8 @@
 #include "config.h"
 #endif
 
+#define WIN32
+
 #if defined(WIN32) || defined(__WIN32__)
 #else
 
