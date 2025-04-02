--- ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceSerialUART.h.orig	2025-04-02 18:10:22 UTC
+++ ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceSerialUART.h
@@ -72,6 +72,6 @@ class MSPBSL_PhysicalInterfaceSerialUART : public MSPB
 	virtual std::string getErrorInformation( uint16_t err );
 
 private:
-    boost::asio::io_service io;
+    boost::asio::io_context io;
     boost::asio::serial_port* port;
 };
