--- src/xml.cpp.orig	2015-10-21 17:26:38 UTC
+++ src/xml.cpp
@@ -47,17 +47,17 @@ XMLElement::getAttribute(const string& k
 void
 XMLElement::xml_start(void *data, const XML_Char *name, const XML_Char **atts) {
 	XMLElement *el = reinterpret_cast<XMLElement *>(data);
-	XMLElement new_el(name);
+	std::shared_ptr<XMLElement> new_el(new XMLElement(name));
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
 
@@ -71,7 +71,7 @@ XMLElement::xml_end(void *data, const XM
 void
 XMLElement::xml_text(void *data, const XML_Char *text, int len) {
 	XMLElement *el = reinterpret_cast<XMLElement *>(data);
-	el->_parsingStack.back()->second._text.append(text, len);
+	el->_parsingStack.back()->second->_text.append(text, len);
 }
 
 int
