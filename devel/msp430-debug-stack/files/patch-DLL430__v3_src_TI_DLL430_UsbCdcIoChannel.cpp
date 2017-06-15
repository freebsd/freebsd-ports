--- DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.cpp.orig	2016-05-02 09:51:53.763023000 +0200
+++ DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.cpp	2016-05-02 09:53:56.332580000 +0200
@@ -303,6 +303,22 @@
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
@@ -324,6 +340,7 @@
 				ifNumStream >> interfaceNumber;
 				if (modalias.find(cdcIdStream.str()) == 0 && interfaceNumber == 0)
 				{
+#endif
 					const string filename = it->path().filename().string();
 					const string portPath = string("/dev/") + filename;
 
