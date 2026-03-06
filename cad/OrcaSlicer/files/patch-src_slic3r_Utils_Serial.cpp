--- src/slic3r/Utils/Serial.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/Utils/Serial.cpp
@@ -278,11 +278,11 @@ using boost::system::error_code;
 namespace asio = boost::asio;
 using boost::system::error_code;
 
-Serial::Serial(asio::io_service& io_service) :
+Serial::Serial(asio::io_context& io_service) :
 	asio::serial_port(io_service)
 {}
 
-Serial::Serial(asio::io_service& io_service, const std::string &name, unsigned baud_rate) :
+Serial::Serial(asio::io_context& io_service, const std::string &name, unsigned baud_rate) :
 	asio::serial_port(io_service, name)
 {
 	set_baud_rate(baud_rate);
@@ -342,6 +342,11 @@ void Serial::set_baud_rate(unsigned baud_rate)
 		ios.c_cc[VTIME] = 1;
 		handle_errno(::ioctl(handle, TCSETS2, &ios));
 
+#elif defined(__FreeBSD__)
+		struct termios ios;
+		handle_errno(::tcgetattr(handle, &ios));
+		handle_errno(::cfsetspeed(&ios, baud_rate));
+		handle_errno(::tcsetattr(handle, TCSAFLUSH, &ios));
 #elif __OpenBSD__
 		struct termios ios;
 		handle_errno(::tcgetattr(handle, &ios));
@@ -393,7 +398,7 @@ bool Serial::read_line(unsigned timeout, std::string &
  #else
 		this->get_io_service();
 #endif
-	asio::deadline_timer timer(io_service);
+	asio::steady_timer timer(io_service);
 	char c = 0;
 	bool fail = false;
 
@@ -409,7 +414,7 @@ bool Serial::read_line(unsigned timeout, std::string &
 		});
 
 		if (timeout > 0) {
-			timer.expires_from_now(boost::posix_time::milliseconds(timeout));
+			timer.expires_after(std::chrono::milliseconds(timeout));
 			timer.async_wait([&](const error_code &ec) {
 				// Ignore timer aborts
 				if (!ec) {
