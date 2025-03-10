--- src/slic3r/Utils/Serial.cpp.orig	2025-02-14 23:15:01 UTC
+++ src/slic3r/Utils/Serial.cpp
@@ -282,11 +282,11 @@ using boost::system::error_code;
 namespace asio = boost::asio;
 using boost::system::error_code;
 
-Serial::Serial(asio::io_service& io_service) :
+Serial::Serial(asio::io_context &io_service) :
 	asio::serial_port(io_service)
 {}
 
-Serial::Serial(asio::io_service& io_service, const std::string &name, unsigned baud_rate) :
+Serial::Serial(asio::io_context &io_service, const std::string &name, unsigned baud_rate) :
 	asio::serial_port(io_service, name)
 {
 	set_baud_rate(baud_rate);
