--- src/xml.h.orig	2015-10-21 17:26:38 UTC
+++ src/xml.h
@@ -13,6 +13,7 @@
 
 #include <string>
 #include <map>
+#include <memory>
 #include <vector>
 #include <utility>
 #include <expat.h>
@@ -28,7 +29,7 @@ namespace tqsllib {
 
 class XMLElement;
 
-typedef multimap<string, XMLElement> XMLElementList;
+typedef multimap<string, std::shared_ptr<XMLElement> > XMLElementList;
 typedef map<string, string> XMLElementAttributeList;
 
 /** Encapsulates an XML element
@@ -62,7 +63,7 @@ class XMLElement {
       */
 	pair<string, bool> getAttribute(const string& key);
 	/// Add an element to the list of contained subelements
-	XMLElementList::iterator addElement(const XMLElement& element);
+	XMLElementList::iterator addElement(std::shared_ptr<XMLElement> element);
 	XMLElementAttributeList& getAttributeList() { return _attributes; }
 	XMLElementList& getElementList() { return _elements; }
 	/// Parse an XML file and add its element tree to this element
@@ -134,8 +135,8 @@ XMLElement::setAttribute(const string& k
 }
 
 inline XMLElementList::iterator
-XMLElement::addElement(const XMLElement& element) {
-	XMLElementList::iterator it = _elements.insert(make_pair(element.getElementName(), element));
+XMLElement::addElement(std::shared_ptr<XMLElement> element) {
+	XMLElementList::iterator it = _elements.insert(make_pair(element->getElementName(), element));
 	return it;
 }
 
@@ -158,9 +159,9 @@ inline bool
 XMLElement::getNextElement(XMLElement& element) {
 	if (_iter == _elements.end())
 		return false;
-	if (_iterByName && _iter->second.getElementName() != _iterName)
+	if (_iterByName && _iter->second->getElementName() != _iterName)
 		return false;
-	element = _iter->second;
+	element = *_iter->second;
 	++_iter;
 	return true;
 }
