--- dabreceiver-V2/backend/mm_malloc.h.orig	2013-05-22 11:09:20 UTC
+++ dabreceiver-V2/backend/mm_malloc.h
@@ -40,7 +40,9 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #if defined(_WIN32) || defined(_WIN64)
 #define MALLOC(a) _mm_malloc(a, 16)
 #else
+#if ! (defined __FreeBSD__ || defined __DragonFly__)
 #include <malloc.h>
+#endif
 #define MALLOC(a) memalign(16, a)
 #endif
 
