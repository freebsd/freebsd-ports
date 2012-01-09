--- src/mongoose/mongoose.c.orig	2012-01-08 11:06:17.000000000 +0800
+++ src/mongoose/mongoose.c	2012-01-08 11:08:32.000000000 +0800
@@ -18,6 +18,10 @@
 // OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 // THE SOFTWARE.
 
+#if defined(__FreeBSD__)
+#include <sys/socket.h>
+#endif
+
 #if defined(_WIN32)
 #define _CRT_SECURE_NO_WARNINGS // Disable deprecation warning in VS2005
 #else