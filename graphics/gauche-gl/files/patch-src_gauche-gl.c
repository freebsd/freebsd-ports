--- src/gauche-gl.c.orig	Mon Jan  8 14:47:05 2007
+++ src/gauche-gl.c	Mon Jan  8 14:55:21 2007
@@ -139,11 +139,7 @@
 */
 void *Scm_GLGetProcAddress(const char *name)
 {
-#if defined(GLX_ARB_get_proc_address)
-    if (glXGetProcAddressARB != NULL) {
-        return glXGetProcAddressARB((const GLubyte*)name);
-    }
-#elif defined(GLX_VERSION_1_4)
+#if defined(GLX_VERSION_1_4)
     if (glXGetProcAddress != NULL) {
         return glXGetProcAddress(name);
     }
