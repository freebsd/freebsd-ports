--- src/address.cpp.orig	2020-10-31 09:53:52 UTC
+++ src/address.cpp
@@ -49,7 +49,7 @@ bool GetMac(std::vector<unsigned char>& mac)
 	return (GetMacType(mac, 0));
 }
 
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 
 bool GetMac(std::vector<unsigned char>& mac)
 {
