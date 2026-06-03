--- media/gpu/chromeos/gl_image_processor_backend.cc.orig	2026-04-28 21:06:17 UTC
+++ media/gpu/chromeos/gl_image_processor_backend.cc
@@ -27,6 +27,10 @@
 #include "ui/ozone/public/ozone_platform.h"
 #include "ui/ozone/public/surface_factory_ozone.h"
 
+#ifndef GL_CONTEXT_LOST_KHR
+#define GL_CONTEXT_LOST_KHR 0x0507
+#endif
+
 namespace media {
 
 namespace {
