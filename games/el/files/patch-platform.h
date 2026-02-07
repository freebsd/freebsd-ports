--- platform.h.orig	2021-04-11 19:03:51 UTC
+++ platform.h
@@ -11,7 +11,7 @@
 // http://predef.sourceforge.net/prearch.html , these ought to work on
 // gcc, Sun Studio and Visual Studio.
 // Throw in ia64 as well, though I doubt anyone will play EL on that.
-#if defined (__x86_64__) || defined (_M_X64) || defined (__ia64__) || defined (_M_IA64)
+#if defined (__x86_64__) || defined (_M_X64) || defined (__ia64__) || defined (_M_IA64) || defined (__amd64__)
  #define X86_64
 #endif
 
@@ -85,16 +85,13 @@
  #include "elglext.h"
  #define APIENTRY 
  #define APIENTRYP *
-#elif !defined(BSD)
+#else
  #define GL_GLEXT_LEGACY
  #include <GL/gl.h>
  #include <GL/glu.h>
  #undef GL_VERSION_1_2
  #undef GL_VERSION_1_3
- #include "glext.h"
-#else // BSD
- #include <GL/gl.h>
- #include <GL/glu.h>
+ #include <GL/glext.h>
 #endif
 
 // Inlucde the plaform specific location sound libs
