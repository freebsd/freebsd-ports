--- src/modules/graphics/opengl/Graphics.cpp.orig	2012-04-06 18:15:01 UTC
+++ src/modules/graphics/opengl/Graphics.cpp
@@ -18,6 +18,7 @@
 * 3. This notice may not be removed or altered from any source distribution.
 **/
 
+#define GL_GLEXT_PROTOTYPES
 #include <common/config.h>
 #include <common/math.h>
 #include <common/Vector.h>
