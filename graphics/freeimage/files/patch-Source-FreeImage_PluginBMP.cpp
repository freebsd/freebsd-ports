--- Source/FreeImage/PluginBMP.cpp.orig	2008-06-13 00:40:16.000000000 +0200
+++ Source/FreeImage/PluginBMP.cpp	2008-06-13 00:46:51.000000000 +0200
@@ -224,7 +224,7 @@
 				throw(1);
 			}
 			if (status_byte != 0)	{
-				status_byte = MIN(status_byte, end - q);
+				status_byte = MIN((size_t)status_byte, (size_t)(end - q));
 				// Encoded mode
 				if(io->read_proc(&second_byte, sizeof(BYTE), 1, handle) != 1) {
 					throw(1);
@@ -279,7 +279,7 @@
 					default:
 					{
 						// Absolute mode
-						status_byte = MIN(status_byte, end - q);
+						status_byte = MIN((size_t)status_byte, (size_t)(end - q));
 						for (int i = 0; i < status_byte; i++) {
 							if ((i & 0x01) == 0) {
 								if(io->read_proc(&second_byte, sizeof(BYTE), 1, handle) != 1) {
