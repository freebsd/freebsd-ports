--- server/supernova/sc/sc_osc_handler.hpp.orig	2020-11-15 17:38:26 UTC
+++ server/supernova/sc/sc_osc_handler.hpp
@@ -229,11 +229,7 @@ class sc_osc_handler : private detail::network_thread,
     class tcp_connection : public nova_endpoint {
     public:
         using pointer = std::shared_ptr<tcp_connection>;
-#if BOOST_VERSION >= 107000
-        using executor = boost::asio::executor;
-#else
-        using executor = boost::asio::io_context::executor_type;
-#endif
+        using executor = tcp::socket::executor_type;
 
         static pointer create(const executor& executor) { return pointer(new tcp_connection(executor)); }
 
@@ -244,11 +240,7 @@ class sc_osc_handler : private detail::network_thread,
         bool operator==(tcp_connection const& rhs) const { return &rhs == this; }
 
     private:
-#if BOOST_VERSION >= 107000
         tcp_connection(const executor& executor): socket_(executor) {}
-#else
-        tcp_connection(const executor& executor): socket_(executor.context()) {}
-#endif
 
         void send(const char* data, size_t length) override final;
 
