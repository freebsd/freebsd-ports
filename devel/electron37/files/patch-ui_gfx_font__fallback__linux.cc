--- ui/gfx/font_fallback_linux.cc.orig	2024-10-16 21:32:39 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -32,6 +32,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
