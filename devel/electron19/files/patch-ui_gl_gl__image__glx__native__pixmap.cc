--- ui/gl/gl_image_glx_native_pixmap.cc.orig	2022-05-19 05:18:01 UTC
+++ ui/gl/gl_image_glx_native_pixmap.cc
@@ -16,6 +16,8 @@
 #include "ui/gl/buffer_format_utils.h"
 #include "ui/gl/gl_bindings.h"
 
+#include <unistd.h>
+
 namespace gl {
 
 namespace {
