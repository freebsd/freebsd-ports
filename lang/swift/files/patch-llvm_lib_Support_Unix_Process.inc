--- llvm/lib/Support/Unix/Process.inc.orig	2016-02-26 00:51:43 UTC
+++ llvm/lib/Support/Unix/Process.inc
@@ -36,7 +36,7 @@
 // DragonFlyBSD, OpenBSD, and Bitrig have deprecated <malloc.h> for
 // <stdlib.h> instead. Unix.h includes this for us already.
 #if defined(HAVE_MALLOC_H) && !defined(__DragonFly__) && \
-    !defined(__OpenBSD__) && !defined(__Bitrig__)
+    !defined(__OpenBSD__) && !defined(__Bitrig__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 #if defined(HAVE_MALLCTL)
