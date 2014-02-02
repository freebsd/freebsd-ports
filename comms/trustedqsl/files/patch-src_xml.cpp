--- src/xml.cpp.orig	2013-10-20 20:33:20.000000000 -0400
+++ src/xml.cpp	2014-02-01 20:30:26.874285772 -0500
@@ -17,6 +17,33 @@
 using namespace std;
 
 namespace tqsllib {
+static	XMLElementList::iterator _iter;
+
+bool
+XMLElement::getFirstElement(XMLElement& element) {
+	_iterByName = false;
+	_iter = _elements.begin();
+	return getNextElement(element);
+}
+
+bool
+XMLElement::getFirstElement(const std::string& name, XMLElement& element) {
+	_iterName = name;
+	_iterByName = true;
+	_iter = _elements.find(_iterName);
+	return getNextElement(element);
+}
+
+bool
+XMLElement::getNextElement(XMLElement& element) {
+	if (_iter == _elements.end())
+		return false;
+	if (_iterByName && _iter->second.getElementName() != _iterName)
+		return false;
+	element = _iter->second;
+	++_iter;
+	return true;
+}
 
 pair<string,bool>
 XMLElement::getAttribute(const string& key) {
