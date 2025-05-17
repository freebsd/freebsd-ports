--- content/browser/web_contents/web_contents_view_aura_unittest.cc.orig	2025-04-22 20:15:27 UTC
+++ content/browser/web_contents/web_contents_view_aura_unittest.cc
@@ -40,7 +40,7 @@
 #include "ui/base/dragdrop/os_exchange_data_provider_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 #include "ui/base/x/selection_utils.h"
 #include "ui/base/x/x11_os_exchange_data_provider.h"
 #include "ui/gfx/x/atom_cache.h"
@@ -96,7 +96,7 @@ class TestDragDropClient : public aura::client::DragDr
     drag_drop_data_ = std::move(data);
     return DragOperation::kCopy;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void UpdateDragImage(const gfx::ImageSkia& image,
                        const gfx::Vector2d& offset) override {}
 #endif
@@ -231,7 +231,7 @@ TEST_F(WebContentsViewAuraTest, WebContentsDestroyedDu
                              ui::EF_LEFT_MOUSE_BUTTON, 0);
   ui::EventHandler* event_handler = GetView();
   event_handler->OnMouseEvent(&mouse_event);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The web-content is not activated during mouse-press on Linux.
   // See comment in WebContentsViewAura::OnMouseEvent() for more details.
   EXPECT_NE(web_contents(), nullptr);
@@ -297,7 +297,7 @@ TEST_F(WebContentsViewAuraTest, MAYBE_DragDropFiles) {
   view->OnDragEntered(event);
   ASSERT_NE(nullptr, view->current_drag_data_);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // By design, Linux implementations return an empty string if file data
   // is also present.
   EXPECT_TRUE(!view->current_drag_data_->text ||
@@ -337,7 +337,7 @@ TEST_F(WebContentsViewAuraTest, MAYBE_DragDropFiles) {
 
   CheckDropData(view);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // By design, Linux implementations returns an empty string if file data
   // is also present.
   EXPECT_TRUE(!drop_complete_data_->drop_data.text ||
@@ -395,7 +395,7 @@ TEST_F(WebContentsViewAuraTest, MAYBE_DragDropFilesOri
   view->OnDragEntered(event);
   ASSERT_NE(nullptr, view->current_drag_data_);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // By design, Linux implementations return an empty string if file data
   // is also present.
   EXPECT_TRUE(!view->current_drag_data_->text ||
@@ -427,7 +427,7 @@ TEST_F(WebContentsViewAuraTest, MAYBE_DragDropFilesOri
 
   CheckDropData(view);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // By design, Linux implementations returns an empty string if file data is
   // also present.
   EXPECT_TRUE(!drop_complete_data_->drop_data.text ||
@@ -458,7 +458,7 @@ TEST_F(WebContentsViewAuraTest, MAYBE_DragDropImageFro
 
   auto data = std::make_unique<ui::OSExchangeData>();
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   // FileContents drag-drop in X relies on XDragDropClient::InitDrag() setting
   // window property 'XdndDirectSave0' to filename. Since XDragDropClient is not
   // created in this unittest, we will set this property manually to allow
