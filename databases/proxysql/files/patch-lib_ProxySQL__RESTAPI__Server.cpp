--- lib/ProxySQL_RESTAPI_Server.cpp.orig	2024-04-01 15:50:50 UTC
+++ lib/ProxySQL_RESTAPI_Server.cpp
@@ -346,7 +346,7 @@ ProxySQL_RESTAPI_Server::ProxySQL_RESTAPI_Server(
 	// NOTE: Right now ProxySQL is using the simplest mode of 'libhttpserver' for serving 'REST' queries,
 	// in the current mode concurrency on serving requests is low, and throughput is directly related with
 	// the time required to execute the target script, since each of the calls are blocking.
-	ws = std::unique_ptr<httpserver::webserver>(new webserver(create_webserver(p)));
+	ws = std::unique_ptr<httpserver::webserver>(new webserver(create_webserver(p).start_method(http::http_utils::start_method_T::THREAD_PER_CONNECTION)));
 	// NOTE: Enable for benchmarking purposes. In this mode each request will be served by it's own thread.
 	// ws = std::unique_ptr<httpserver::webserver>(new webserver(create_webserver(p).start_method(http::http_utils::start_method_T::THREAD_PER_CONNECTION)));
 	auto sr = new sync_resource();
