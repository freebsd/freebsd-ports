--- DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.cpp.orig	2017-12-05 19:25:19.220234000 +0300
+++ DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.cpp	2017-12-05 19:31:57.808647000 +0300
@@ -309,6 +309,22 @@
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
@@ -330,6 +346,7 @@
 				ifNumStream >> interfaceNumber;
 				if (modalias.find(cdcIdStream.str()) == 0 && interfaceNumber == 0)
 				{
+#endif
 					const string filename = it->path().filename().string();
 					const string portPath = string("/dev/") + filename;
 
@@ -375,7 +392,11 @@
 
 bool UsbCdcIoChannel::openPort()
 {
+#if BOOST_VERSION < 106600
 	ioService = new boost::asio::io_service;
+#else
+	ioService = new boost::asio::io_context;
+#endif
 	port = new boost::asio::serial_port(*ioService);
 	timer = new boost::asio::deadline_timer(*ioService);
 
@@ -384,7 +405,7 @@
 		int retry = 5;
 		while (ec && --retry )
 		{
-			this_thread::sleep_for(chrono::milliseconds(5));
+			this_thread::sleep_for(std::chrono::milliseconds(5));
 			ec = port->open(portInfo.path, ec);
 		}
 
@@ -409,7 +430,7 @@
 	{
 		openPort();
 		//Seeing issues on some platforms (eg. Ubuntu) when port is immediately closed again
-		this_thread::sleep_for(chrono::milliseconds(100));
+		this_thread::sleep_for(std::chrono::milliseconds(100));
 		close();
 	}
 }
