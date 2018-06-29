--- include/libunwind_i.h.orig	2018-06-15 23:58:15 UTC
+++ include/libunwind_i.h
@@ -86,6 +86,11 @@ WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
 #   error Host has unknown byte-order.
 # endif
 #endif
+#ifdef __FreeBSD__
+#define __BYTE_ORDER BYTE_ORDER
+#define __LITTLE_ENDIAN LITTLE_ENDIAN
+#define __BIG_ENDIAN BIG_ENDIAN
+#endif
 
 #if defined(HAVE__BUILTIN_UNREACHABLE)
 # define unreachable() __builtin_unreachable()
