--- minisat-2.2.1/minisat/mtl/IntTypes.h.orig	2011-02-21 13:31:17 UTC
+++ minisat-2.2.1/minisat/mtl/IntTypes.h
@@ -31,7 +31,9 @@ OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OT
 #else
 
 #   include <stdint.h>
+#ifndef _MSC_VER
 #   include <inttypes.h>
+#endif
 
 #endif
 
