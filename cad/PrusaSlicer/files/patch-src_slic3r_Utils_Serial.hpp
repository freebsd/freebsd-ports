--- src/slic3r/Utils/Serial.hpp.orig	2025-02-14 23:32:07 UTC
+++ src/slic3r/Utils/Serial.hpp
@@ -43,8 +43,8 @@ class Serial : public boost::asio::serial_port (public
 class Serial : public boost::asio::serial_port
 {
 public:
-	Serial(boost::asio::io_service &io_service);
-	Serial(boost::asio::io_service &io_service, const std::string &name, unsigned baud_rate);
+	Serial(boost::asio::io_context &io_service);
+	Serial(boost::asio::io_context &io_service, const std::string &name, unsigned baud_rate);
 	Serial(const Serial &) = delete;
 	Serial &operator=(const Serial &) = delete;
 	~Serial();
