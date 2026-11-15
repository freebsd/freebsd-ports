--- gpu/command_buffer/service/raster_decoder_unittest_context_lost.cc.orig	2026-11-05 12:23:53 UTC
+++ gpu/command_buffer/service/raster_decoder_unittest_context_lost.cc
@@ -19,6 +19,18 @@ using ::testing::SetArrayArgument;
 using ::testing::SaveArg;
 using ::testing::SetArrayArgument;
 
+#ifndef GL_CONTEXT_LOST_KHR
+#define GL_CONTEXT_LOST_KHR 0x0507
+#endif
+
+#ifndef GL_GUILTY_CONTEXT_RESET_KHR
+#define GL_GUILTY_CONTEXT_RESET_KHR 0x8253
+#endif
+
+#ifndef GL_INNOCENT_CONTEXT_RESET_KHR
+#define GL_INNOCENT_CONTEXT_RESET_KHR 0x8254
+#endif
+
 namespace gpu {
 namespace raster {
 
