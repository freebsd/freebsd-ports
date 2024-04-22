--- minisat-2.2.1/minisat/mtl/XAlloc.h.orig	2011-02-21 13:31:17 UTC
+++ minisat-2.2.1/minisat/mtl/XAlloc.h
@@ -21,7 +21,6 @@ OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OT
 #ifndef Minisat_XAlloc_h
 #define Minisat_XAlloc_h
 
-#include <errno.h>
 #include <stdlib.h>
 
 namespace Minisat {
@@ -33,7 +32,7 @@ static inline void* xrealloc(void *ptr, size_t size)
 static inline void* xrealloc(void *ptr, size_t size)
 {
     void* mem = realloc(ptr, size);
-    if (mem == NULL && errno == ENOMEM){
+    if (mem == NULL){
         throw OutOfMemoryException();
     }else
         return mem;
