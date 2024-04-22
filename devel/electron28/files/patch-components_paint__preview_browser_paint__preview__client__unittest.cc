--- components/paint_preview/browser/paint_preview_client_unittest.cc.orig	2022-02-28 16:54:41 UTC
+++ components/paint_preview/browser/paint_preview_client_unittest.cc
@@ -171,8 +171,8 @@ TEST_P(PaintPreviewClientRenderViewHostTest, CaptureMa
   metadata->set_url(expected_url.spec());
   metadata->set_version(kPaintPreviewVersion);
   auto* chromeVersion = metadata->mutable_chrome_version();
-  chromeVersion->set_major(CHROME_VERSION_MAJOR);
-  chromeVersion->set_minor(CHROME_VERSION_MINOR);
+  chromeVersion->set_gmajor(CHROME_VERSION_MAJOR);
+  chromeVersion->set_gminor(CHROME_VERSION_MINOR);
   chromeVersion->set_build(CHROME_VERSION_BUILD);
   chromeVersion->set_patch(CHROME_VERSION_PATCH);
   PaintPreviewFrameProto* main_frame = expected_proto.mutable_root_frame();
