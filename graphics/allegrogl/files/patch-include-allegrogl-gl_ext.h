--- include/allegrogl/gl_ext.h.orig	Sun Dec 14 01:19:34 2003
+++ include/allegrogl/gl_ext.h	Thu Jan 22 14:46:25 2004
@@ -12,7 +12,7 @@
 #include "allegrogl/GLext/gl_ext_defs.h"
 #ifdef ALLEGRO_WINDOWS
 #include "allegrogl/GLext/wgl_ext_defs.h"
-#elif defined ALLEGRO_LINUX
+#elif defined ALLEGRO_LINUX || defined __FreeBSD__
 #include "allegrogl/GLext/glx_ext_defs.h"
 #endif
 
@@ -27,7 +27,7 @@
 #	include "allegrogl/GLext/gl_ext_api.h"
 #ifdef ALLEGRO_WINDOWS
 #	include "allegrogl/GLext/wgl_ext_api.h"
-#elif defined ALLEGRO_LINUX
+#elif defined ALLEGRO_LINUX || defined __FreeBSD__
 #	include "allegrogl/GLext/glx_ext_api.h"
 #endif
 #undef AGL_API
@@ -46,7 +46,7 @@
 #define AGL_API(type, name, args) extern AGL_##name##_t wgl##name;
 #	include "allegrogl/GLext/wgl_ext_api.h"
 #undef AGL_API
-#elif defined ALLEGRO_LINUX
+#elif defined ALLEGRO_LINUX || defined __FreeBSD__
 #define AGL_API(type, name, args) extern AGL_##name##_t glX##name;
 #	include "allegrogl/GLext/glx_ext_api.h"
 #undef AGL_API
