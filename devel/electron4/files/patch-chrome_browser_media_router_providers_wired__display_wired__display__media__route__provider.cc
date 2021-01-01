--- chrome/browser/media/router/providers/wired_display/wired_display_media_route_provider.cc.orig	2019-03-15 06:37:03 UTC
+++ chrome/browser/media/router/providers/wired_display/wired_display_media_route_provider.cc
@@ -111,6 +111,12 @@ void WiredDisplayMediaRouteProvider::CreateRoute(
     bool incognito,
     CreateRouteCallback callback) {
   DCHECK(!base::ContainsKey(presentations_, presentation_id));
+#if defined(OS_BSD) // XXX
+   std::move(callback).Run(base::nullopt, nullptr,
+                           std::string("Not implemented"),
+                           RouteRequestResult::UNKNOWN_ERROR);
+   return;
+#else
   base::Optional<Display> display = GetDisplayBySinkId(sink_id);
   if (!display) {
     std::move(callback).Run(base::nullopt, std::string("Display not found"),
@@ -135,6 +141,7 @@ void WiredDisplayMediaRouteProvider::CreateRoute(
   presentation.receiver()->Start(presentation_id, GURL(media_source));
   std::move(callback).Run(route, base::nullopt, RouteRequestResult::OK);
   NotifyRouteObservers();
+#endif
 }
 
 void WiredDisplayMediaRouteProvider::JoinRoute(
