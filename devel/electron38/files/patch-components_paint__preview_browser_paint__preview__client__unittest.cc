--- components/paint_preview/browser/paint_preview_client_unittest.cc.orig	2025-08-26 20:49:50 UTC
+++ components/paint_preview/browser/paint_preview_client_unittest.cc
@@ -172,8 +172,8 @@ TEST_P(PaintPreviewClientRenderViewHostTest, CaptureMa
   metadata->set_version(kPaintPreviewVersion);
   auto* chromeVersion = metadata->mutable_chrome_version();
   const auto& current_chrome_version = version_info::GetVersion();
-  chromeVersion->set_major(current_chrome_version.components()[0]);
-  chromeVersion->set_minor(current_chrome_version.components()[1]);
+  chromeVersion->set_gmajor(current_chrome_version.components()[0]);
+  chromeVersion->set_gminor(current_chrome_version.components()[1]);
   chromeVersion->set_build(current_chrome_version.components()[2]);
   chromeVersion->set_patch(current_chrome_version.components()[3]);
   PaintPreviewFrameProto* main_frame = expected_proto.mutable_root_frame();
