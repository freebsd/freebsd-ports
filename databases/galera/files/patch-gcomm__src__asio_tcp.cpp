--- gcomm/src/asio_tcp.cpp.orig	2017-01-25 07:55:06 UTC
+++ gcomm/src/asio_tcp.cpp
@@ -231,10 +231,18 @@ void gcomm::AsioTcpSocket::close()
     }
 }
 
+// Enable to introduce random errors for write handler
+// #define GCOMM_ASIO_TCP_SIMULATE_WRITE_HANDLER_ERROR
 
 void gcomm::AsioTcpSocket::write_handler(const asio::error_code& ec,
                                          size_t bytes_transferred)
 {
+#ifdef GCOMM_ASIO_TCP_SIMULATE_WRITE_HANDLER_ERROR
+    static const long empty_rate(10000);
+    static const long bytes_transferred_less_than_rate(10000);
+    static const long bytes_transferred_not_zero_rate(10000);
+#endif // GCOMM_ASIO_TCP_SIMULATE_WRITE_HANDLER_ERROR
+
     Critical<AsioProtonet> crit(net_);
 
     if (state() != S_CONNECTED && state() != S_CLOSING)
@@ -252,34 +260,70 @@ void gcomm::AsioTcpSocket::write_handler
 
     if (!ec)
     {
-        gcomm_assert(send_q_.empty() == false);
-        gcomm_assert(send_q_.front().len() >= bytes_transferred);
-
-        while (send_q_.empty() == false &&
-               bytes_transferred >= send_q_.front().len())
+        if (send_q_.empty() == true
+#ifdef GCOMM_ASIO_TCP_SIMULATE_WRITE_HANDLER_ERROR
+            || ::rand() % empty_rate == 0
+#endif // GCOMM_ASIO_TCP_SIMULATE_WRITE_HANDLER_ERROR
+            )
         {
-            const Datagram& dg(send_q_.front());
-            bytes_transferred -= dg.len();
-            send_q_.pop_front();
+            log_warn << "write_handler() called with empty send_q_. "
+                     << "Transport may not be reliable, closing the socket";
+            FAILED_HANDLER(asio::error_code(EPROTO,
+                                            asio::error::system_category));
         }
-        gcomm_assert(bytes_transferred == 0);
-
-        if (send_q_.empty() == false)
+        else if (send_q_.front().len() < bytes_transferred
+#ifdef GCOMM_ASIO_TCP_SIMULATE_WRITE_HANDLER_ERROR
+                 || ::rand() % bytes_transferred_less_than_rate == 0
+#endif // GCOMM_ASIO_TCP_SIMULATE_WRITE_HANDLER_ERROR
+            )
         {
-            const Datagram& dg(send_q_.front());
-            boost::array<asio::const_buffer, 2> cbs;
-            cbs[0] = asio::const_buffer(dg.header()
-                                        + dg.header_offset(),
-                                        dg.header_len());
-            cbs[1] = asio::const_buffer(&dg.payload()[0],
-                                        dg.payload().size());
-            write_one(cbs);
+            log_warn << "write_handler() bytes_transferred "
+                     << bytes_transferred
+                     << " less than sent "
+                     << send_q_.front().len()
+                     << ". Transport may not be reliable, closing the socket";
+            FAILED_HANDLER(asio::error_code(EPROTO,
+                                            asio::error::system_category));
         }
-        else if (state_ == S_CLOSING)
+        else
         {
-            log_debug << "deferred close of " << id();
-            close_socket();
-            state_ = S_CLOSED;
+            while (send_q_.empty() == false &&
+                   bytes_transferred >= send_q_.front().len())
+            {
+                const Datagram& dg(send_q_.front());
+                bytes_transferred -= dg.len();
+                send_q_.pop_front();
+            }
+            if (bytes_transferred != 0
+#ifdef GCOMM_ASIO_TCP_SIMULATE_WRITE_HANDLER_ERROR
+                 || ::rand() % bytes_transferred_not_zero_rate == 0
+#endif // GCOMM_ASIO_TCP_SIMULATE_WRITE_HANDLER_ERROR
+            )
+            {
+                log_warn << "write_handler() bytes_transferred "
+                         << bytes_transferred
+                         << " after processing the send_q_. "
+                         << "Transport may not be reliable, closing the socket";
+                FAILED_HANDLER(asio::error_code(EPROTO,
+                                                asio::error::system_category));
+            }
+            else if (send_q_.empty() == false)
+            {
+                const Datagram& dg(send_q_.front());
+                boost::array<asio::const_buffer, 2> cbs;
+                cbs[0] = asio::const_buffer(dg.header()
+                                            + dg.header_offset(),
+                                            dg.header_len());
+                cbs[1] = asio::const_buffer(&dg.payload()[0],
+                                            dg.payload().size());
+                write_one(cbs);
+            }
+            else if (state_ == S_CLOSING)
+            {
+                log_debug << "deferred close of " << id();
+                close_socket();
+                state_ = S_CLOSED;
+            }
         }
     }
     else if (state_ == S_CLOSING)
