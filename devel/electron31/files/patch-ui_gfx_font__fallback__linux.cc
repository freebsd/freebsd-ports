--- ui/gfx/font_fallback_linux.cc.orig	2024-02-21 00:21:15 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -27,6 +27,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
