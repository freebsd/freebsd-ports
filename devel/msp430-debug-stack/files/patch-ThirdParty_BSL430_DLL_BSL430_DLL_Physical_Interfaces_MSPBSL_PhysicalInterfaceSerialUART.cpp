--- ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceSerialUART.cpp.orig	2017-12-05 18:38:46.034235000 +0300
+++ ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceSerialUART.cpp	2017-12-05 18:39:30.622349000 +0300
@@ -193,27 +193,27 @@ void MSPBSL_PhysicalInterfaceSerialUART:
     
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
 
