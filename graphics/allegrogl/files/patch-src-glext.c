--- src/glext.c.orig	Thu Jan  8 01:04:04 2004
+++ src/glext.c	Thu Jan 22 16:32:43 2004
@@ -20,7 +20,7 @@
 #	include "allegrogl/GLext/gl_ext_api.h"
 #ifdef ALLEGRO_WINDOWS
 #	include "allegrogl/GLext/wgl_ext_api.h"
-#elif defined ALLEGRO_LINUX
+#elif defined ALLEGRO_LINUX || defined __FreeBSD__
 #	include "allegrogl/GLext/glx_ext_api.h"
 #endif
 } AGL_EXT;
@@ -105,7 +105,7 @@
 #define AGL_API(type, name, args) AGL_##name##_t wgl##name = NULL;
 #	include "allegrogl/GLext/wgl_ext_api.h"
 #undef AGL_API
-#elif defined ALLEGRO_LINUX
+#elif defined ALLEGRO_LINUX || defined __FreeBSD__
 #define AGL_API(type, name, args) AGL_##name##_t glX##name = NULL;
 #	include "allegrogl/GLext/glx_ext_api.h"
 #undef AGL_API
@@ -153,7 +153,7 @@
 		if (ext->name) { AGL_LOG(2,"wgl" #name " successfully loaded\n"); }
 #	include "allegrogl/GLext/wgl_ext_api.h"
 #	undef AGL_API
-#	elif defined ALLEGRO_LINUX
+#	elif defined ALLEGRO_LINUX || defined __FreeBSD__
 #	define AGL_API(type, name, args) \
 		ext->name = (AGL_##name##_t)aglXGetProcAddress("gl" #name); \
 		if (ext->name) { AGL_LOG(2,"gl" #name " successfully loaded\n"); }
@@ -197,7 +197,7 @@
 #define AGL_API(type, name, args) wgl##name = ext->name;
 #	include "allegrogl/GLext/wgl_ext_api.h"
 #undef AGL_API
-#elif defined ALLEGRO_LINUX
+#elif defined ALLEGRO_LINUX || defined __FreeBSD__
 #define AGL_API(type, name, args) glX##name = ext->name;
 #	include "allegrogl/GLext/glx_ext_api.h"
 #undef AGL_API
@@ -344,7 +344,7 @@
 		 * we try to find the symbol into the dynamic libs
 		 * that are already loaded (e.g. in libGL.so)
 		 */
-		symbol = dlsym(0, name);
+		symbol = dlsym(RTLD_NEXT, name);
 	}
 #elif defined ALLEGRO_MACOSX
 	function = CFStringCreateWithCString(kCFAllocatorDefault, name,
@@ -439,10 +439,10 @@
 
 	/* Get glXGetProcAddress entry */
 #ifdef ALLEGROGL_HAVE_DYNAMIC_LINK
-	aglXGetProcAddress = (GLXGETPROCADDRESSARBPROC) dlsym(0,
+	aglXGetProcAddress = (GLXGETPROCADDRESSARBPROC) dlsym(RTLD_NEXT,
 	                                                    "glXGetProcAddressARB");
 	if (!aglXGetProcAddress) {
-		aglXGetProcAddress = (GLXGETPROCADDRESSARBPROC) dlsym(0,
+		aglXGetProcAddress = (GLXGETPROCADDRESSARBPROC) dlsym(RTLD_NEXT,
 	                                                       "glXGetProcAddress");
 	}
 	TRACE("glXGetProcAddress Extension: %s\n",
