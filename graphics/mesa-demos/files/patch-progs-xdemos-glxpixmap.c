--- progs/xdemos/glxpixmap.c.orig	Fri Apr  6 22:29:09 2007
+++ progs/xdemos/glxpixmap.c	Fri Apr  6 22:38:33 2007
@@ -105,7 +105,7 @@
     *   to render correctly.  This is because Mesa allows RGB rendering
     *   into any kind of visual, not just TrueColor or DirectColor.
     */
-#ifdef GLX_MESA_pixmap_colormap
+#if defined(GLX_MESA_pixmap_colormap) && !defined(WITH_NVIDIA_GL)
    if (strstr(glXQueryExtensionsString(dpy, 0), "GLX_MESA_pixmap_colormap")) {
       /* stand-alone Mesa, specify the colormap */
       glxpm = glXCreateGLXPixmapMESA( dpy, visinfo, pm, attr.colormap );
