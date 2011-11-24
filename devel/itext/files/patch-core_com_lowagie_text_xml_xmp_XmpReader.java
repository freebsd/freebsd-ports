--- core/com/lowagie/text/xml/xmp/XmpReader.java.orig	2011-11-24 16:34:23.000000000 +0100
+++ core/com/lowagie/text/xml/xmp/XmpReader.java	2011-11-24 16:41:54.000000000 +0100
@@ -103,8 +103,19 @@
 	public boolean replace(String namespaceURI, String localName, String value) {
 		NodeList nodes = domDocument.getElementsByTagNameNS(namespaceURI, localName);
 		Node node;
-		if (nodes.getLength() == 0)
+		if (nodes.getLength() == 0) {
+			nodes = domDocument.getElementsByTagNameNS("http://www.w3.org/1999/02/22-rdf-syntax-ns#", "Description");
+			if (nodes.getLength() == 0) return false;
+			for (int i = 0; i < nodes.getLength(); i++) {
+				node = nodes.item(i);
+				Node attribute = node.getAttributes().getNamedItemNS(namespaceURI, localName);
+				if (attribute != null) {
+					attribute.setNodeValue(value);
+					return true;
+				}
+			}
 			return false;
+		}
 		for (int i = 0; i < nodes.getLength(); i++) {
 			node = nodes.item(i);
 			setNodeText(domDocument, node, value);
