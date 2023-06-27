--- ui/gfx/font_fallback_linux.cc.orig	2022-08-31 12:19:35 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -26,6 +26,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
