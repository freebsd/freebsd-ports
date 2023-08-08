--- src/ptex/PtexPlatform.h.orig	2022-08-05 02:02:51 UTC
+++ src/ptex/PtexPlatform.h
@@ -70,7 +70,9 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY O
 
 // linux/unix/posix
 #include <stdlib.h>
+#if !defined(__FreeBSD__)
 #include <alloca.h>
+#endif
 #include <string.h>
 #include <pthread.h>
 
