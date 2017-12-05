--- DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.cpp.orig	2017-12-05 18:49:13.159254000 +0300
+++ DLL430_v3/src/TI/DLL430/UsbCdcIoChannel.cpp	2017-12-05 18:49:23.590490000 +0300
@@ -401,7 +401,7 @@ bool UsbCdcIoChannel::openPort()
 		int retry = 5;
 		while (ec && --retry )
 		{
-			this_thread::sleep_for(chrono::milliseconds(5));
+			this_thread::sleep_for(std::chrono::milliseconds(5));
 			ec = port->open(portInfo.path, ec);
 		}
 
@@ -426,7 +426,7 @@ void UsbCdcIoChannel::retrieveStatus()
 	{
 		openPort();
 		//Seeing issues on some platforms (eg. Ubuntu) when port is immediately closed again
-		this_thread::sleep_for(chrono::milliseconds(100));
+		this_thread::sleep_for(std::chrono::milliseconds(100));
 		close();
 	}
 }
