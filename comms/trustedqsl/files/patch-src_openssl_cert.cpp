--- src/openssl_cert.cpp.orig	2014-07-12 13:18:13.000000000 -0700
+++ src/openssl_cert.cpp	2014-07-18 05:39:51.000000000 -0700
@@ -4214,23 +4214,23 @@
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
+	shared_ptr<XMLElement> cs(new XMLElement("Cert"));
+	cs->setPretext("\n  ");
+	shared_ptr<XMLElement> se(new XMLElement);
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
