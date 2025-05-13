--- src/VBox/Devices/Graphics/DevVGA-SVGA3d-internal.h.orig	2024-01-11 12:18:21 UTC
+++ src/VBox/Devices/Graphics/DevVGA-SVGA3d-internal.h
@@ -1175,7 +1175,7 @@ typedef struct VMSVGAHWSCREEN
 typedef struct VMSVGAHWSCREEN
 {
     uint32_t u32Reserved0;
-#if defined(RT_OS_LINUX)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
     /* OpenGL context, which is used for the screen updates. */
     GLXContext glxctx;
 
