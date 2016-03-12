--- DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.cpp.orig	2016-03-12 13:23:34 UTC
+++ DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.cpp
@@ -303,6 +303,22 @@ void UsbCdcIoChannel::createCdcPortList(
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
@@ -317,13 +333,14 @@ void UsbCdcIoChannel::createCdcPortList(
 				string modalias;
 				int interfaceNumber = -1;
 
-				ifstream modAliasStream((it->path()/"device/modalias").string().c_str());
+				std::ifstream modAliasStream((it->path()/"device/modalias").string().c_str());
 				modAliasStream >> modalias;
 
-				ifstream ifNumStream((it->path()/"device/bInterfaceNumber").string().c_str());
+				std::ifstream ifNumStream((it->path()/"device/bInterfaceNumber").string().c_str());
 				ifNumStream >> interfaceNumber;
 				if (modalias.find(cdcIdStream.str()) == 0 && interfaceNumber == 0)
 				{
+#endif
 					const string filename = it->path().filename().string();
 					const string portPath = string("/dev/") + filename;
 
