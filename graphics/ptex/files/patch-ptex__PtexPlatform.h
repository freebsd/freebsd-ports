--- src/ptex/PtexPlatform.h.orig	2015-02-12 16:37:58 UTC
+++ src/ptex/PtexPlatform.h
@@ -60,7 +60,9 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 
 // linux/unix/posix
 #include <stdlib.h>
+#if !defined(__FreeBSD__)
 #include <alloca.h>
+#endif
 #include <string.h>
 #include <pthread.h>
 // OS for spinlock
