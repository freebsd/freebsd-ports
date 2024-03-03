--- lib/libimhex/include/hex/helpers/http_requests.hpp.orig	2024-03-03 03:55:21 UTC
+++ lib/libimhex/include/hex/helpers/http_requests.hpp
@@ -148,7 +148,7 @@ namespace hex {
         std::string m_body;
         std::promise<std::vector<u8>> m_promise;
         std::map<std::string, std::string> m_headers;
-        u32 m_timeout = 1000;
+        u32 m_timeout = 100000;
 
         std::atomic<float> m_progress = 0.0F;
         std::atomic<bool> m_canceled = false;
