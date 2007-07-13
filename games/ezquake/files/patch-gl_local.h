--- ./gl_local.h.orig	Thu Jul 12 20:11:59 2007
+++ ./gl_local.h	Thu Jul 12 20:27:57 2007
@@ -299,6 +299,9 @@
 extern lpMTexFUNC qglMultiTexCoord2f;
 extern lpSelTexFUNC qglActiveTexture;
 
+extern PFNGLXGETVIDEOSYNCSGIPROC qglXGetVideoSyncSGI;
+extern PFNGLXWAITVIDEOSYNCSGIPROC qglXWaitVideoSyncSGI;
+
 extern float gldepthmin, gldepthmax;
 extern byte color_white[4], color_black[4];
 extern qbool gl_mtexable;
