--- lib/client.cpp.orig	2023-01-10 04:14:36 UTC
+++ lib/client.cpp
@@ -6,6 +6,7 @@
 #include <thread>
 
 #include "coeurl/request.hpp"
+#include "coeurl/errors.hpp"
 
 namespace coeurl {
 std::shared_ptr<spdlog::logger> Client::log = spdlog::null_logger_mt("coeurl_null");
@@ -352,7 +353,7 @@ void Client::remove_request(Request *r) {
         long http_code;
         curl_easy_getinfo(req->easy, CURLINFO_RESPONSE_CODE, &http_code);
 
-        Client::log->trace("DONE: {} => {} ({}) http: {}", req->url_, req->curl_error, req->error, http_code);
+        Client::log->trace("DONE: {} => {} ({}) http: {}", req->url_, coeurl::to_string(req->curl_error), req->error, http_code);
 
         if (req->on_complete_)
             req->on_complete_(*req.get());
