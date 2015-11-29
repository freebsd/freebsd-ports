--- src/openssl_cert.cpp.orig	2015-10-21 17:26:38 UTC
+++ src/openssl_cert.cpp
@@ -3353,18 +3353,18 @@ tqsl_restoreCallsignCertificate(const ch
 	for (ep = ellist.find("UserCert"); ep != ellist.end(); ep++) {
 		if (ep->first != "UserCert")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("CallSign");
+		pair<string, bool> rval = ep->second->getAttribute("CallSign");
 		if (rval.second) call = rval.first;
-		rval = ep->second.getAttribute("serial");
+		rval = ep->second->getAttribute("serial");
 		if (rval.second) serial = strtol(rval.first.c_str(), NULL, 10);
-		rval = ep->second.getAttribute("dxcc");
+		rval = ep->second->getAttribute("dxcc");
 		if (rval.second) dxcc = strtol(rval.first.c_str(), NULL, 10);
 
 		XMLElement el;
-		if (ep->second.getFirstElement("SignedCert", el)) {
+		if (ep->second->getFirstElement("SignedCert", el)) {
 			publicKey = el.getText();
 		}
-		if (ep->second.getFirstElement("PrivateKey", el)) {
+		if (ep->second->getFirstElement("PrivateKey", el)) {
 			privateKey = el.getText();
 		}
 	}
@@ -5208,23 +5208,23 @@ tqsl_setCertificateStatus(long serial, c
 	for (ep = ellist.find("Cert"); ep != ellist.end(); ep++) {
 		if (ep->first != "Cert")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("serial");
+		pair<string, bool> rval = ep->second->getAttribute("serial");
 		if (rval.second && strtol(rval.first.c_str(), NULL, 10) == serial) {
 			exists = true;
 			break;
 		}
 	}
 
-	XMLElement cs("Cert");
-	cs.setPretext("\n  ");
-	XMLElement se;
-	se.setPretext(cs.getPretext() + "  ");
-	se.setElementName("status");
-	se.setText(status);
-	cs.addElement(se);
+	std::shared_ptr<XMLElement> cs(new XMLElement("Cert"));
+	cs->setPretext("\n  ");
+	std::shared_ptr<XMLElement> se(new XMLElement);
+	se->setPretext(cs->getPretext() + "  ");
+	se->setElementName("status");
+	se->setText(status);
+	cs->addElement(se);
 
-	cs.setAttribute("serial", sstr);
-	cs.setText("\n  ");
+	cs->setAttribute("serial", sstr);
+	cs->setText("\n  ");
 
 	if (exists)
 		ellist.erase(ep);
