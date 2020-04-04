--- DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.cpp.orig	2020-02-14 09:38:32 UTC
+++ DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.cpp
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
 
