--- dabreceiver-V2/backend/mm_malloc.h.orig
+++ dabreceiver-V2/backend/mm_malloc.h
@@ -40,7 +40,9 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #if defined(_WIN32) || defined(_WIN64)
 #define MALLOC(a) _mm_malloc(a, 16)
 #else
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 #define MALLOC(a) memalign(16, a)
 #endif
 
