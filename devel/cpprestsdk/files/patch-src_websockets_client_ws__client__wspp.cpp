--- src/websockets/client/ws_client_wspp.cpp.orig	2023-12-05 04:23:31 UTC
+++ src/websockets/client/ws_client_wspp.cpp
@@ -225,7 +225,7 @@ class wspp_callback_client : public websocket_client_c
                             verifyCtx, utility::conversions::to_utf8string(m_uri.host()));
                     }
 #endif
-                    boost::asio::ssl::rfc2818_verification rfc2818(utility::conversions::to_utf8string(m_uri.host()));
+                    boost::asio::ssl::host_name_verification rfc2818(utility::conversions::to_utf8string(m_uri.host()));
                     return rfc2818(preverified, verifyCtx);
                 });
 
