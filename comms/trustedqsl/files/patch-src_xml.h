--- src/xml.h.orig	2013-10-20 20:33:20.000000000 -0400
+++ src/xml.h	2014-02-01 20:20:55.798824124 -0500
@@ -108,7 +108,6 @@
 	XMLElementAttributeList _attributes;
 	XMLElementList _elements;
 	std::vector<XMLElementList::iterator> _parsingStack;
-	XMLElementList::iterator _iter;
 	bool _iterByName;
 	std::string _iterName;
 	XMLElementAttributeList::iterator _aiter;
@@ -132,6 +131,7 @@
 	return it;
 }
 
+#if 0
 inline bool
 XMLElement::getFirstElement(XMLElement& element) {
 	_iterByName = false;
@@ -157,6 +157,7 @@
 	++_iter;
 	return true;
 }
+#endif
 
 inline bool
 XMLElement::getFirstAttribute(std::string& key, std::string& attr) {
