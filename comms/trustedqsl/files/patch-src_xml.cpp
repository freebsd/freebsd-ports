--- src/xml.cpp.orig	2014-05-08 17:59:25.000000000 -0700
+++ src/xml.cpp	2014-05-24 04:26:40.000000000 -0700
@@ -20,9 +20,20 @@
 using std::string;
 using std::ostream;
 using std::map;
+#ifdef USE_TR1
+using std::tr1::shared_ptr;
+#else
+using std::make_shared;
+#endif
 
 namespace tqsllib {
 
+shared_ptr<XMLElement> make_shared_XMLElement(XMLElement *e)
+{
+	shared_ptr<XMLElement> p(e);
+	return p;
+}
+
 pair<string, bool>
 XMLElement::getAttribute(const string& key) {
 	string s;
@@ -49,9 +60,9 @@
 	if (el->_parsingStack.empty()) {
 		el->_parsingStack.push_back(el->addElement(new_el));
 	} else {
-		new_el.setPretext(el->_parsingStack.back()->second.getText());
-		el->_parsingStack.back()->second.setText("");
-		el->_parsingStack.push_back(el->_parsingStack.back()->second.addElement(new_el));
+		new_el.setPretext(el->_parsingStack.back()->second.elem->getText());
+		el->_parsingStack.back()->second.elem->setText("");
+		el->_parsingStack.push_back(el->_parsingStack.back()->second.elem->addElement(new_el));
 	}
 }
 
@@ -65,7 +76,7 @@
 void
 XMLElement::xml_text(void *data, const XML_Char *text, int len) {
 	XMLElement *el = reinterpret_cast<XMLElement *>(data);
-	el->_parsingStack.back()->second._text.append(text, len);
+	el->_parsingStack.back()->second.elem->_text.append(text, len);
 }
 
 /*
