GCC on 9.x doesn't allow types to be overwritten, these types are defined
in drm.h also, which causes build issues in xorg-server.

--- include/GL/internal/dri_interface.h.orig	2016-11-10 22:05:17 UTC
+++ include/GL/internal/dri_interface.h
@@ -40,13 +40,7 @@
 #ifndef DRI_INTERFACE_H
 #define DRI_INTERFACE_H
 
-#ifdef HAVE_LIBDRM
 #include <drm.h>
-#else
-typedef unsigned int drm_context_t;
-typedef unsigned int drm_drawable_t;
-typedef struct drm_clip_rect drm_clip_rect_t;
-#endif
 
 /**
  * \name DRI interface structures
