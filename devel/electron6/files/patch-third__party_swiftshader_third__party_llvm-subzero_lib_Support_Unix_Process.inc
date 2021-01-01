--- third_party/swiftshader/third_party/llvm-subzero/lib/Support/Unix/Process.inc.orig	2019-09-10 10:47:53 UTC
+++ third_party/swiftshader/third_party/llvm-subzero/lib/Support/Unix/Process.inc
@@ -35,7 +35,7 @@
 // DragonFlyBSD, OpenBSD, and Bitrig have deprecated <malloc.h> for
 // <stdlib.h> instead. Unix.h includes this for us already.
 #if defined(HAVE_MALLOC_H) && !defined(__DragonFly__) && \
-    !defined(__OpenBSD__) && !defined(__Bitrig__)
+    !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__Bitrig__)
 #include <malloc.h>
 #endif
 #if defined(HAVE_MALLCTL)
