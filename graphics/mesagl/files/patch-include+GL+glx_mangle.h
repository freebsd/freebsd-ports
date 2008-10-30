--- include/GL/glx_mangle.h.orig	2008-07-15 00:24:26.000000000 -0500
+++ include/GL/glx_mangle.h	2008-07-15 00:26:19.000000000 -0500
@@ -51,5 +51,59 @@
 /* GLX 1.4 */
 #define glXGetProcAddress mglXGetProcAddress
 
+/* ADDED by KSB@llnl for VisIt */
+
+#define glXAllocateMemoryNV mglXAllocateMemoryNV
+#define glXBindChannelToWindowSGIX mglXBindChannelToWindowSGIX
+#define glXBindSwapBarrierSGIX mglXBindSwapBarrierSGIX
+#define glXChannelRectSGIX mglXChannelRectSGIX
+#define glXChannelRectSyncSGIX mglXChannelRectSyncSGIX
+#define glXChooseFBConfig mglXChooseFBConfig
+#define glXChooseFBConfigSGIX mglXChooseFBConfigSGIX
+#define glXCreateContextWithConfigSGIX mglXCreateContextWithConfigSGIX
+#define glXCreateGLXPbufferSGIX mglXCreateGLXPbufferSGIX
+#define glXCreateGLXPixmapWithConfigSGIX mglXCreateGLXPixmapWithConfigSGIX
+#define glXCreateNewContext mglXCreateNewContext
+#define glXCreatePbuffer mglXCreatePbuffer
+#define glXCreatePixmap mglXCreatePixmap
+#define glXCreateWindow mglXCreateWindow
+#define glXCushionSGI mglXCushionSGI
+#define glXDestroyGLXPbufferSGIX mglXDestroyGLXPbufferSGIX
+#define glXDestroyPbuffer mglXDestroyPbuffer
+#define glXDestroyPixmap mglXDestroyPixmap
+#define glXDestroyWindow mglXDestroyWindow
+#define glXFreeContextEXT mglXFreeContextEXT
+#define glXFreeMemoryNV mglXFreeMemoryNV
+#define glXGetContextIDEXT mglXGetContextIDEXT
+#define glXGetCurrentDisplay mglXGetCurrentDisplay
+#define glXGetCurrentDisplayEXT mglXGetCurrentDisplayEXT
+#define glXGetCurrentReadDrawable mglXGetCurrentReadDrawable
+#define glXGetCurrentReadDrawableSGI mglXGetCurrentReadDrawableSGI
+#define glXGetFBConfigAttrib mglXGetFBConfigAttrib
+#define glXGetFBConfigAttribSGIX mglXGetFBConfigAttribSGIX
+#define glXGetFBConfigFromVisualSGIX mglXGetFBConfigFromVisualSGIX
+#define glXGetFBConfigs mglXGetFBConfigs
+#define glXGetProcAddressARB mglXGetProcAddressARB
+#define glXGetSelectedEvent mglXGetSelectedEvent
+#define glXGetSelectedEventSGIX mglXGetSelectedEventSGIX
+#define glXGetTransparentIndexSUN mglXGetTransparentIndexSUN
+#define glXGetVisualFromFBConfig mglXGetVisualFromFBConfig
+#define glXGetVisualFromFBConfigSGIX mglXGetVisualFromFBConfigSGIX
+#define glXImportContextEXT mglXImportContextEXT
+#define glXJoinSwapGroupSGIX mglXJoinSwapGroupSGIX
+#define glXMakeContextCurrent mglXMakeContextCurrent
+#define glXMakeCurrentReadSGI mglXMakeCurrentReadSGI
+#define glXQueryChannelDeltasSGIX mglXQueryChannelDeltasSGIX
+#define glXQueryChannelRectSGIX mglXQueryChannelRectSGIX
+#define glXQueryContext mglXQueryContext
+#define glXQueryContextInfoEXT mglXQueryContextInfoEXT
+#define glXQueryDrawable mglXQueryDrawable
+#define glXQueryGLXPbufferSGIX mglXQueryGLXPbufferSGIX
+#define glXQueryMaxSwapBarriersSGIX mglXQueryMaxSwapBarriersSGIX
+#define glXSelectEvent mglXSelectEvent
+#define glXSelectEventSGIX mglXSelectEventSGIX
+#define glXSet3DfxModeMESA mglXSet3DfxModeMESA
+#define glXSwapIntervalSGI mglXSwapIntervalSGI
+
 
 #endif
