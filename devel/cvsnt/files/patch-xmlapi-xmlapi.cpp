--- xmlapi/xmlapi.cpp.orig	Tue Feb  8 21:27:08 2005
+++ xmlapi/xmlapi.cpp	Tue Feb  8 21:26:30 2005
@@ -41,7 +41,7 @@
 	else n->value="";
 	n->Parent=this;
 	if(n->XmlType==XmlTypeNode)
-		n->Parent->value.clear(); /* We don't support mixing trees and labels... this also papers over a small quirk in the loading routine */
+		n->Parent->value.erase(); /* We don't support mixing trees and labels... this also papers over a small quirk in the loading routine */
 	return n;
 }
 
@@ -365,7 +365,7 @@
 
 bool XmlNode::BatchDelete()
 {
-	name.clear(); /* Having no name marks the tag for deletion */
+	name.erase(); /* Having no name marks the tag for deletion */
 	return true;
 }
 
@@ -374,6 +374,11 @@
 static bool operator==(std::pair<const std::string,XmlNode>& a,XmlNode *b)
 { 
 	return &a.second == b;
+}
+
+static bool operator!=(std::pair<const std::string,XmlNode>& a,XmlNode *b)
+{
+	return &a.second != b;
 }
 
 XmlNode::ChildArray_t::iterator XmlNode::FindIterator(XmlNode *node)
