--- sources/titleblock/templatescollection.cpp.orig	2026-01-28 12:19:13 UTC
+++ sources/titleblock/templatescollection.cpp
@@ -454,7 +454,7 @@ QDomElement TitleBlockTemplatesFilesCollection::getTem
 	}
 
 	QDomDocument *xml_document = new QDomDocument();
-	bool xml_parsing = xml_document -> setContent(&xml_file);
+	bool xml_parsing = static_cast<bool>(xml_document -> setContent(&xml_file));
 	if (!xml_parsing) {
 		delete xml_document;
 		return(QDomElement());
