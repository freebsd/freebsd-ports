--- ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceSerialUART.cpp.orig	2025-04-02 18:13:20 UTC
+++ ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceSerialUART.cpp
@@ -129,7 +129,7 @@ MSPBSL_PhysicalInterfaceSerialUART::MSPBSL_PhysicalInt
 
 
 	//TODO: Catch exception forunknown ports
-	io_service io;
+	io_context io;
     port = new serial_port( io, PORT );
 	port->set_option( serial_port_base::character_size( 8 ) );
 	port->set_option( serial_port_base::flow_control( serial_port_base::flow_control::none ) );
