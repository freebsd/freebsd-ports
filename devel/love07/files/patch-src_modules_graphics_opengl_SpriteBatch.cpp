--- src/modules/graphics/opengl/SpriteBatch.cpp.orig	2011-05-04 16:00:10 UTC
+++ src/modules/graphics/opengl/SpriteBatch.cpp
@@ -18,6 +18,7 @@
 * 3. This notice may not be removed or altered from any source distribution.
 **/
 
+#define GL_GLEXT_PROTOTYPES
 #include "SpriteBatch.h"
 
 // STD
