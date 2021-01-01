--- thirdparty/glew/glew.c.orig	2017-12-28 02:06:18 UTC
+++ thirdparty/glew/glew.c
@@ -30,7 +30,7 @@
 ** THE POSSIBILITY OF SUCH DAMAGE.
 */
 
-#include <GL/glew.h>
+#include "thirdparty/glew/GL/glew.h"
 
 #if defined(_WIN32)
 #  include <GL/wglew.h>
