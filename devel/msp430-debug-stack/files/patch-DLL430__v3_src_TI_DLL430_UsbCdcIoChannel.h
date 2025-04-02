--- DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.h.orig	2025-04-02 18:10:46 UTC
+++ DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.h
@@ -45,7 +45,7 @@
 
 #include <boost/asio/serial_port.hpp>
 #include <boost/asio/deadline_timer.hpp>
-#include <boost/asio/io_service.hpp>
+#include <boost/asio/io_context.hpp>
 
 namespace TI
 {
@@ -74,7 +74,7 @@ namespace TI
 
 		private:
 			std::vector<uint8_t> inputBuffer;
-			boost::asio::io_service* ioService;
+			boost::asio::io_context* ioService;
 			boost::asio::serial_port* port;
 			boost::asio::deadline_timer* timer;
 			ComState comState;
