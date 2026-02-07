Delete a test case that tries to fail to connect to an
unconnectable address, but instead fails because network-sandbox
prevents the connection.

Bug: https://bugs.gentoo.org/954810

--- libs/beast/test/beast/core/basic_stream.cpp.orig	2025-08-06 18:49:08 UTC
+++ libs/beast/test/beast/core/basic_stream.cpp
@@ -1014,24 +1014,6 @@ class basic_stream_test (public)
         //
 
         {
-            // normal timeout
-            // Requires timeout happen before ECONNREFUSED 
-            stream_type s(ioc);
-            auto const ep = net::ip::tcp::endpoint(
-            #if 1
-                // This address _should_ be unconnectible
-                net::ip::make_address("72.5.65.111"), 1);
-            #else
-                // On Travis ECONNREFUSED happens before the timeout
-                net::ip::make_address("127.0.0.1"), 1);
-            #endif
-            s.expires_after(std::chrono::seconds(0));
-            s.async_connect(ep, connect_handler{error::timeout});
-            ioc.run_for(std::chrono::seconds(1));
-            ioc.restart();
-        }
-
-        {
             // stream destroyed
             {
                 stream_type s(ioc);
