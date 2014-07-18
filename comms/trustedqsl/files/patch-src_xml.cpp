--- src/xml.cpp.orig	2014-07-12 13:18:13.000000000 -0700
+++ src/xml.cpp	2014-07-18 05:40:18.000000000 -0700
@@ -20,6 +20,11 @@
 using std::string;
 using std::ostream;
 using std::map;
+#ifdef USE_TR1
+using std::tr1::shared_ptr;
+#else
+using std::make_shared;
+#endif
 
 namespace tqsllib {
 
@@ -41,17 +46,17 @@
 void
 XMLElement::xml_start(void *data, const XML_Char *name, const XML_Char **atts) {
 	XMLElement *el = reinterpret_cast<XMLElement *>(data);
-	XMLElement new_el(name);
+	shared_ptr<XMLElement> new_el(new XMLElement(name));
 //cout << "Element: " << name << endl;
 	for (int i = 0; atts[i]; i += 2) {
-		new_el.setAttribute(atts[i], atts[i+1]);
+		new_el->setAttribute(atts[i], atts[i+1]);
 	}
 	if (el->_parsingStack.empty()) {
 		el->_parsingStack.push_back(el->addElement(new_el));
 	} else {
-		new_el.setPretext(el->_parsingStack.back()->second.getText());
-		el->_parsingStack.back()->second.setText("");
-		el->_parsingStack.push_back(el->_parsingStack.back()->second.addElement(new_el));
+		new_el->setPretext(el->_parsingStack.back()->second->getText());
+		el->_parsingStack.back()->second->setText("");
+		el->_parsingStack.push_back(el->_parsingStack.back()->second->addElement(new_el));
 	}
 }
 
@@ -65,7 +70,7 @@
 void
 XMLElement::xml_text(void *data, const XML_Char *text, int len) {
 	XMLElement *el = reinterpret_cast<XMLElement *>(data);
-	el->_parsingStack.back()->second._text.append(text, len);
+	el->_parsingStack.back()->second->_text.append(text, len);
 }
 
 /*
