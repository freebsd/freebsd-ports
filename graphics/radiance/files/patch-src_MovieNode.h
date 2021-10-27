--- src/MovieNode.h.orig	2021-10-17 01:26:30 UTC
+++ src/MovieNode.h
@@ -9,7 +9,7 @@
 #include <QOpenGLShaderProgram>
 #include <mpv/client.h>
 #include <mpv/opengl_cb.h>
-#include <mpv/qthelper.hpp>
+#include "mpv/qthelper.hpp" // removed file manually copied in, see https://github.com/mpv-player/mpv/blob/575197ff8b0a0d8cd14f7ee78461c1d61d045d72/DOCS/client-api-changes.rst#api-changes
 #include <vector>
 #include <array>
 
