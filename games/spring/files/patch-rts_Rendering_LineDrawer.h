https://github.com/spring/spring/pull/554

--- rts/Rendering/LineDrawer.h.orig	2020-12-26 12:45:43 UTC
+++ rts/Rendering/LineDrawer.h
@@ -4,6 +4,7 @@
 #define _LINE_DRAWER_H
 
 #include <vector>
+#include <array>
 
 #include "Game/UI/CursorIcons.h"
 #include "Rendering/GL/VertexArrayTypes.h"
