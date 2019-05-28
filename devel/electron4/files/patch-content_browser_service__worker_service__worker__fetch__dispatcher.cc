--- content/browser/service_worker/service_worker_fetch_dispatcher.cc.orig	2019-03-15 06:37:21 UTC
+++ content/browser/service_worker/service_worker_fetch_dispatcher.cc
@@ -695,7 +695,7 @@ bool ServiceWorkerFetchDispatcher::MaybeStartNavigatio
   network::ResourceRequest request;
   request.method = original_request->method();
   request.url = original_request->url();
-  // TODO(horo): Set site_for_cookies to support Same-site Cookies.
+  request.site_for_cookies = original_request->site_for_cookies();
   request.request_initiator =
       original_request->initiator().has_value()
           ? original_request->initiator()
