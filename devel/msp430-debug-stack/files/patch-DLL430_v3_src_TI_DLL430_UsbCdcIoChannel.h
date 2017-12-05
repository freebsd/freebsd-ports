--- DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.h.orig	2017-12-05 19:32:41.218250000 +0300
+++ DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.h	2017-12-05 19:33:09.405049000 +0300
@@ -73,7 +73,11 @@
 
 		private:
 			std::vector<uint8_t> inputBuffer;
+#if BOOST_VERSION < 106600
 			boost::asio::io_service* ioService;
+#else
+			boost::asio::io_context* ioService;
+#endif
 			boost::asio::serial_port* port;
 			boost::asio::deadline_timer* timer;
 			ComState comState;
