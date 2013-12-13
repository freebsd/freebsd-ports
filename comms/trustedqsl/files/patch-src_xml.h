--- src/xml.h.orig	2013-12-12 13:03:46.814700681 -0500
+++ src/xml.h	2013-12-12 13:04:09.019718129 -0500
@@ -108,12 +108,13 @@
 	XMLElementAttributeList _attributes;
 	XMLElementList _elements;
 	std::vector<XMLElementList::iterator> _parsingStack;
-	XMLElementList::iterator _iter;
 	bool _iterByName;
 	std::string _iterName;
 	XMLElementAttributeList::iterator _aiter;
 };
 
+static	XMLElementList::iterator _iter;
+
 inline void XMLElement::clear() {
 	_name = _text = _pretext = _iterName = "";
 	_attributes.clear();
