--- chrome/browser/media/router/providers/wired_display/wired_display_media_route_provider.cc.orig	2021-04-14 01:08:40 UTC
+++ chrome/browser/media/router/providers/wired_display/wired_display_media_route_provider.cc
@@ -105,6 +105,12 @@ void WiredDisplayMediaRouteProvider::CreateRoute(
     bool off_the_record,
     CreateRouteCallback callback) {
   DCHECK(!base::Contains(presentations_, presentation_id));
+#if defined(OS_BSD)
+  std::move(callback).Run(base::nullopt, nullptr,
+		          std::string("Not implemented"),
+			  RouteRequestResult::UNKNOWN_ERROR);
+  return;
+#else
   base::Optional<Display> display = GetDisplayBySinkId(sink_id);
   if (!display) {
     std::move(callback).Run(base::nullopt, nullptr,
@@ -131,6 +137,7 @@ void WiredDisplayMediaRouteProvider::CreateRoute(
   std::move(callback).Run(route, nullptr, base::nullopt,
                           RouteRequestResult::OK);
   NotifyRouteObservers();
+#endif
 }
 
 void WiredDisplayMediaRouteProvider::JoinRoute(
