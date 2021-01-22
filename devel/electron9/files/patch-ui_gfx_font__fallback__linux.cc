--- ui/gfx/font_fallback_linux.cc.orig	2020-05-26 07:49:14 UTC
+++ ui/gfx/font_fallback_linux.cc
@@ -24,6 +24,10 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#if defined(OS_BSD)
+#include <unistd.h>
+#endif
+
 namespace gfx {
 
 namespace {
