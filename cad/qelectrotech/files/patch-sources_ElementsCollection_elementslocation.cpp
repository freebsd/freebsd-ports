--- sources/ElementsCollection/elementslocation.cpp.orig	2026-01-28 12:19:13 UTC
+++ sources/ElementsCollection/elementslocation.cpp
@@ -802,18 +802,17 @@ bool ElementsLocation::setXml(const QDomDocument &xml_
 #pragma message("@TODO remove code for QT 6 or later")
 #		pragma message("@TODO ad Core5Compat to Cmake")
 #endif
-			qDebug() << "Help code for QT 6 or later";
-
 			QString			   path_ = collectionPath(false);
 			QRegularExpression rx("^(.*)/(.*\\.elmt)$");
+			QRegularExpressionMatch match = rx.match(path_);
 
-			if (rx.exactMatch(path_))
+			if (match.hasMatch())
 			{
 				return project()
 					->embeddedElementCollection()
 					->addElementDefinition(
-						rx.cap(1),
-						rx.cap(2),
+						match.captured(1),
+						match.captured(2),
 						xml_document.documentElement());
 			}
 			else
