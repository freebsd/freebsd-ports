--- AstroMenaceSource/Core/Base.h~
+++ AstroMenaceSource/Core/Base.h
@@ -46,10 +46,14 @@
 	#include <OpenGL/gl.h>	// Header File For The OpenGL32 Library
 	#include <OpenGL/glu.h>	// Header File For The GLu32 Library
 #else
+    #ifdef OLD_MESA
 	#define __glext_h_  // Don't let gl.h include glext.h
+    #endif
 	#include <GL/gl.h>	// Header File For The OpenGL32 Library
 	#include <GL/glu.h>	// Header File For The GLu32 Library
+    #ifdef OLD_MESA
 	#undef __glext_h_
+    #endif
 #endif
 
 #include <stdlib.h> // rand, ...
