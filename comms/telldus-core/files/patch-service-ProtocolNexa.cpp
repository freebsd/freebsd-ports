--- service/ProtocolNexa.cpp.orig	2014-03-31 12:30:09.000000000 +0200
+++ service/ProtocolNexa.cpp	2016-04-04 13:32:35.124699000 +0200
@@ -56,7 +56,7 @@ std::string ProtocolNexa::getStringForMe
 			// We also return the last packet so Device::doAction() doesn't
 			// report TELLSTICK_ERROR_METHOD_NOT_SUPPORTED
 
-			str.insert(0, 1, 2);  // Repeat two times
+			str.insert(0, 1, '\x2');  // Repeat two times
 			str.insert(0, 1, 'R');
 			for (int i = 0; i < 5; ++i) {
 				controller->send(str);
