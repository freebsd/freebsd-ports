--- src/openssl_cert.cpp	2014-05-08 17:59:25.000000000 -0700
+++ ../../work.fixed/tqsl-2.0.2/src/openssl_cert.cpp	2014-05-24 00:28:34.000000000 -0700
@@ -4214,7 +4214,7 @@
 	for (ep = ellist.find("Cert"); ep != ellist.end(); ep++) {
 		if (ep->first != "Cert")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("serial");
+		pair<string, bool> rval = ep->second.elem->getAttribute("serial");
 		if (rval.second && strtol(rval.first.c_str(), NULL, 10) == serial) {
 			exists = true;
 			break;
