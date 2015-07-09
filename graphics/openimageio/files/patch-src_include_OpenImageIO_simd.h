--- src/include/OpenImageIO/simd.h.orig	2015-06-23 11:59:51 UTC
+++ src/include/OpenImageIO/simd.h
@@ -52,8 +52,10 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #if (defined(__SSE2__) || (_MSC_VER >= 1300 && !_M_CEE_PURE)) && !defined(OIIO_NO_SSE)
 #  include <xmmintrin.h>
 #  include <emmintrin.h>
-#  if defined(__SSE3__) || defined(__SSSE3__)
+#  if defined(__SSE3__)
 #    include <pmmintrin.h>
+#  endif
+#  if defined(__SSSE3__)
 #    include <tmmintrin.h>
 #  endif
 #  if (defined(__SSE4_1__) || defined(__SSE4_2__))

