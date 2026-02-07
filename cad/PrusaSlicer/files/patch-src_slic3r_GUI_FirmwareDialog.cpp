--- src/slic3r/GUI/FirmwareDialog.cpp.orig	2025-02-14 23:34:27 UTC
+++ src/slic3r/GUI/FirmwareDialog.cpp
@@ -365,7 +365,7 @@ bool FirmwareDialog::priv::check_model_id()
 	// 	return true;
 	// }
 
-	// asio::io_service io;
+	// asio::io_context io;
 	// Serial serial(io, port->port, 115200);
 	// serial.printer_setup();
 
@@ -429,7 +429,7 @@ void FirmwareDialog::priv::avr109_reboot(const SerialP
 
 void FirmwareDialog::priv::avr109_reboot(const SerialPortInfo &port)
 {
-	asio::io_service io;
+	asio::io_context io;
 	Serial serial(io, port.port, 1200);
 	std::this_thread::sleep_for(std::chrono::milliseconds(50));
 }
