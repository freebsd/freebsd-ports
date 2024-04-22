--- minisat-2.2.1/minisat/utils/System.h.orig	2011-02-21 13:31:17 UTC
+++ minisat-2.2.1/minisat/utils/System.h
@@ -21,7 +21,7 @@ OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OT
 #ifndef Minisat_System_h
 #define Minisat_System_h
 
-#if defined(__linux__)
+#if defined(__linux__) && defined(__GLIBC__)
 #include <fpu_control.h>
 #endif
 
