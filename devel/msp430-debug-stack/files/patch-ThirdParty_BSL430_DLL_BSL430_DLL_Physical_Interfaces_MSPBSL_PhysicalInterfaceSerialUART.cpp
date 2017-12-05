--- ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceSerialUART.cpp.orig	2017-12-05 19:25:19.310735000 +0300
+++ ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceSerialUART.cpp	2017-12-05 19:34:23.723027000 +0300
@@ -129,7 +129,11 @@
 
 
 	//TODO: Catch exception forunknown ports
+#if BOOST_VERSION < 106600
 	io_service io;
+#else
+	io_context io;
+#endif
     port = new serial_port( io, PORT );
 	port->set_option( serial_port_base::character_size( 8 ) );
 	port->set_option( serial_port_base::flow_control( serial_port_base::flow_control::none ) );
@@ -193,27 +197,27 @@
     
 	port->set_option(RESETControl(LOW_SIGNAL));
 	port->set_option(TESTControl(LOW_SIGNAL));
-	this_thread::sleep_for(chrono::milliseconds(10));
+	this_thread::sleep_for(std::chrono::milliseconds(10));
 	port->set_option(TESTControl(HIGH_SIGNAL));
-	this_thread::sleep_for(chrono::milliseconds(10));
+	this_thread::sleep_for(std::chrono::milliseconds(10));
 	port->set_option(TESTControl(LOW_SIGNAL));
-	this_thread::sleep_for(chrono::milliseconds(10));
+	this_thread::sleep_for(std::chrono::milliseconds(10));
 	port->set_option(TESTControl(HIGH_SIGNAL));
-	this_thread::sleep_for(chrono::milliseconds(10));
+	this_thread::sleep_for(std::chrono::milliseconds(10));
 	if( method == STANDARD_INVOKE )
 	{
 	  port->set_option(RESETControl(HIGH_SIGNAL));
-	  this_thread::sleep_for(chrono::milliseconds(10));
+	  this_thread::sleep_for(std::chrono::milliseconds(10));
 	  port->set_option(TESTControl(LOW_SIGNAL));
 	}
 	else if ( method == BSL_XXXX_INVOKE )
 	{
 	  port->set_option(TESTControl(LOW_SIGNAL));
-	  this_thread::sleep_for(chrono::milliseconds(10));
+	  this_thread::sleep_for(std::chrono::milliseconds(10));
 	  port->set_option(RESETControl(HIGH_SIGNAL));
 	}
 	
-	this_thread::sleep_for(chrono::milliseconds(250));
+	this_thread::sleep_for(std::chrono::milliseconds(250));
 	
 }
 
