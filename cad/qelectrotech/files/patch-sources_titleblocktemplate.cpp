--- sources/titleblocktemplate.cpp.orig	2026-01-28 12:19:13 UTC
+++ sources/titleblocktemplate.cpp
@@ -103,7 +103,7 @@ bool TitleBlockTemplate::loadFromXmlFile(const QString
 
 	// parse its content as XML
 	QDomDocument xml_doc;
-	bool xml_parsing = xml_doc.setContent(&template_file);
+	bool xml_parsing = static_cast<bool>(xml_doc.setContent(&template_file));
 	if (!xml_parsing) {
 		return(false);
 	}
