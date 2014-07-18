--- src/xml.h.orig	2014-07-12 13:18:13.000000000 -0700
+++ src/xml.h	2014-07-18 05:43:47.000000000 -0700
@@ -16,6 +16,14 @@
 #include <vector>
 #include <utility>
 #include <expat.h>
+#if defined(__GNUC__) && !defined(__clang__)
+#define USE_TR1
+#endif
+#ifdef USE_TR1
+#include <tr1/memory>
+#else
+#include <memory>
+#endif
 
 using std::pair;
 using std::string;
@@ -23,12 +31,19 @@
 using std::map;
 using std::multimap;
 using std::vector;
+#ifdef USE_TR1
+using std::tr1::shared_ptr;
+#else
+using std::shared_ptr;
+using std::make_shared;
+#endif
+
 
 namespace tqsllib {
 
 class XMLElement;
 
-typedef multimap<string, XMLElement> XMLElementList;
+typedef multimap<string, shared_ptr<XMLElement> > XMLElementList;
 typedef map<string, string> XMLElementAttributeList;
 
 /** Encapsulates an XML element
@@ -62,7 +77,7 @@
       */
 	pair<string, bool> getAttribute(const string& key);
 	/// Add an element to the list of contained subelements
-	XMLElementList::iterator addElement(const XMLElement& element);
+	XMLElementList::iterator addElement(shared_ptr<XMLElement>& element);
 	XMLElementAttributeList& getAttributeList() { return _attributes; }
 	XMLElementList& getElementList() { return _elements; }
 	/// Parse an XML file and add its element tree to this element
@@ -134,8 +149,8 @@
 }
 
 inline XMLElementList::iterator
-XMLElement::addElement(const XMLElement& element) {
-	XMLElementList::iterator it = _elements.insert(make_pair(element.getElementName(), element));
+XMLElement::addElement(shared_ptr<XMLElement>& element) {
+	XMLElementList::iterator it = _elements.insert(make_pair(element->getElementName(), element));
 	return it;
 }
 
@@ -158,9 +173,9 @@
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
