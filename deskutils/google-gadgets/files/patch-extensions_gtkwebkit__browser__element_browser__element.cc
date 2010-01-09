
$FreeBSD$

--- extensions/gtkwebkit_browser_element/browser_element.cc.orig
+++ extensions/gtkwebkit_browser_element/browser_element.cc
@@ -540,7 +540,7 @@
                                        Impl *impl) {
     if (!impl->owner_) return;
     gint width = 0;
-    g_object_get(features, "width", &width, NULL);
+    g_object_get(features, "width", &width, (const gchar*)0);
     ScopedLogContext log_context(impl->owner_->GetView()->GetGadget());
     DLOG("WebViewWindowWidthNotify(Impl=%p, width=%d)", impl, width);
   }
@@ -550,7 +550,7 @@
                                         Impl *impl) {
     if (!impl->owner_) return;
     gint height = 0;
-    g_object_get(features, "height", &height, NULL);
+    g_object_get(features, "height", &height, (const gchar*)0);
     ScopedLogContext log_context(impl->owner_->GetView()->GetGadget());
     DLOG("WebViewWindowHeightNotify(Impl=%p, width=%d)", impl, height);
   }
