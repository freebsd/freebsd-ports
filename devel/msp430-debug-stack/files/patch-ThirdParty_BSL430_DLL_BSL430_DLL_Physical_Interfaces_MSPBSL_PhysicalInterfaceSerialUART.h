--- ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceSerialUART.h.orig	2017-12-05 19:35:16.469154000 +0300
+++ ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceSerialUART.h	2017-12-05 19:35:38.930835000 +0300
@@ -72,6 +72,10 @@
 	virtual std::string getErrorInformation( uint16_t err );
 
 private:
+#if BOOST_VERSION < 106600
     boost::asio::io_service io;
+#else
+    boost::asio::io_context io;
+#endif
     boost::asio::serial_port* port;
 };
