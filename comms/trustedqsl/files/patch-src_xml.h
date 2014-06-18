--- src/xml.h.orig	2014-05-08 17:59:25.000000000 -0700
+++ src/xml.h	2014-05-24 04:17:00.000000000 -0700
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
@@ -23,12 +31,28 @@
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
 
+
 class XMLElement;
+shared_ptr<XMLElement> make_shared_XMLElement(XMLElement *e);
+class XMLElementP {
+	public:
+		XMLElementP() {}
+		XMLElementP(shared_ptr<XMLElement> new_elem) { elem = new_elem; }
+
+		shared_ptr<XMLElement> elem;
+};
 
-typedef multimap<string, XMLElement> XMLElementList;
+typedef multimap<string, XMLElementP> XMLElementList;
 typedef map<string, string> XMLElementAttributeList;
 
 /** Encapsulates an XML element
@@ -62,7 +86,7 @@
       */
 	pair<string, bool> getAttribute(const string& key);
 	/// Add an element to the list of contained subelements
-	XMLElementList::iterator addElement(const XMLElement& element);
+	XMLElementList::iterator addElement(XMLElement& element);
 	XMLElementAttributeList& getAttributeList() { return _attributes; }
 	XMLElementList& getElementList() { return _elements; }
 	/// Parse an XML file and add its element tree to this element
@@ -134,8 +158,8 @@
 }
 
 inline XMLElementList::iterator
-XMLElement::addElement(const XMLElement& element) {
-	XMLElementList::iterator it = _elements.insert(make_pair(element.getElementName(), element));
+XMLElement::addElement(XMLElement& element) {
+	XMLElementList::iterator it = _elements.insert(make_pair(element.getElementName(), make_shared_XMLElement(&element)));
 	return it;
 }
 
@@ -158,9 +182,9 @@
 XMLElement::getNextElement(XMLElement& element) {
 	if (_iter == _elements.end())
 		return false;
-	if (_iterByName && _iter->second.getElementName() != _iterName)
+	if (_iterByName && _iter->second.elem->getElementName() != _iterName)
 		return false;
-	element = _iter->second;
+	element = *_iter->second.elem.get();
 	++_iter;
 	return true;
 }
