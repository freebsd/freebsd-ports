--- src/libslic3r/GCodeSender.hpp.orig	2025-10-02 17:32:12 UTC
+++ src/libslic3r/GCodeSender.hpp
@@ -35,7 +35,7 @@ class GCodeSender : private boost::noncopyable {
     void reset();
     
     private:
-    asio::io_service io;
+    asio::io_context io;
     asio::serial_port serial;
     boost::thread background_thread;
     boost::asio::streambuf read_buffer, write_buffer;
