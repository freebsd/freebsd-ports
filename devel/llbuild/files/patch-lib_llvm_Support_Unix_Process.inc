--- lib/llvm/Support/Unix/Process.inc.orig	2016-10-20 04:49:37 UTC
+++ lib/llvm/Support/Unix/Process.inc
@@ -33,10 +33,10 @@
 #if HAVE_SIGNAL_H
 #include <signal.h>
 #endif
-// DragonFlyBSD, OpenBSD, and Bitrig have deprecated <malloc.h> for
+// DragonFlyBSD, FreeBSD, OpenBSD, and Bitrig have deprecated <malloc.h> for
 // <stdlib.h> instead. Unix.h includes this for us already.
 #if defined(HAVE_MALLOC_H) && !defined(__DragonFly__) && \
-    !defined(__OpenBSD__) && !defined(__Bitrig__)
+    !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__Bitrig__)
 #include <malloc.h>
 #endif
 #if defined(HAVE_MALLCTL)
