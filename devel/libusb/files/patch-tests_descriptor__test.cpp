
$FreeBSD$

--- tests/descriptor_test.cpp.orig
+++ tests/descriptor_test.cpp
@@ -34,9 +34,9 @@
 
 			cout << bus->directoryName() << "/" 
 				 << device->fileName() << "     "
-				 << uppercase << hex << setw(4) << setfill('0')
+				 << hex << setw(4) << setfill('0')
 				 << device->idVendor() << "/"
-				 << uppercase << hex << setw(4) << setfill('0')
+				 << hex << setw(4) << setfill('0')
 				 << device->idProduct() << endl;
 			if (device->Vendor() != "") {
 				cout << "- Manufacturer : " << device->Vendor() << endl;
