--- core/com/lowagie/text/xml/xmp/XmpReader.java.orig	2016-10-26 08:23:27 UTC
+++ core/com/lowagie/text/xml/xmp/XmpReader.java
@@ -103,8 +103,19 @@ public class XmpReader {
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
