--- DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.cpp.orig	2025-02-14 17:38:09 UTC
+++ DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.cpp
@@ -42,7 +42,7 @@
 
 #include <boost/asio/read.hpp>
 #include <boost/asio/write.hpp>
-#include <boost/asio/io_service.hpp>
+#include <boost/asio/io_context.hpp>
 
 #if defined(_WIN32) || defined(_WIN64)
 
@@ -181,7 +181,7 @@ void UsbCdcIoChannel::createCdcPortList(const uint16_t
 
 	for (;;)
 	{
-		io_service_t device = IOIteratorNext(iterator);
+		io_context_t device = IOIteratorNext(iterator);
 		if (device == 0)
 		{
 			if (!IOIteratorIsValid(iterator))
@@ -310,6 +310,22 @@ void UsbCdcIoChannel::createCdcPortList(const uint16_t
 	}
 #else
 	stringstream cdcIdStream;
+
+#ifdef __FreeBSD__
+
+	path p( "/dev" );
+	if( exists(p) && is_directory(p) ) {
+
+		cdcIdStream << hex << setfill('0') << "mspfet" << setw(4) << productId;
+
+		const directory_iterator end;
+		for( directory_iterator it(p); it != end; ++it ) {
+
+			string dir = it->path().string();
+			if( dir.find( cdcIdStream.str() ) != string::npos ) {
+	      			{
+
+#else
 	cdcIdStream << hex << setfill('0') << "usb:v" << setw(4) << vendorId << "p" << setw(4) << productId;
 
 	path p("/sys/class/tty/");
@@ -331,6 +347,7 @@ void UsbCdcIoChannel::createCdcPortList(const uint16_t
 				ifNumStream >> interfaceNumber;
 				if (modalias.find(cdcIdStream.str()) == 0 && interfaceNumber == 0)
 				{
+#endif
 					const string filename = it->path().filename().string();
 					const string portPath = string("/dev/") + filename;
 
@@ -376,7 +393,7 @@ bool UsbCdcIoChannel::openPort()
 
 bool UsbCdcIoChannel::openPort()
 {
-	ioService = new boost::asio::io_service;
+	ioService = new boost::asio::io_context;
 	port = new boost::asio::serial_port(*ioService);
 	timer = new boost::asio::deadline_timer(*ioService);
 
@@ -542,7 +559,7 @@ size_t UsbCdcIoChannel::read(HalResponse& resp)
 
 	boost::system::error_code ec;
 
-	while (ioService->run_one(ec))
+	while (ioService->run_one())
 	{
 		if (readEvent)
 		{
@@ -577,13 +594,13 @@ size_t UsbCdcIoChannel::read(HalResponse& resp)
 
 		if (ioService->stopped())
 		{
-			ioService->reset();
+			ioService->restart();
 		}
 	}
 
 	//Let cancelled tasks finish
-	ioService->run(ec);
-	ioService->reset();
+	ioService->run();
+	ioService->restart();
 
 
 	if (actSize == expSize)
