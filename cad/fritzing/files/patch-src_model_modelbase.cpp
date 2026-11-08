--- src/model/modelbase.cpp.orig	2026-07-28 07:36:38 UTC
+++ src/model/modelbase.cpp
@@ -979,7 +979,7 @@ ModelPart * ModelBase::createOldSchematicPartAux(Model
 	}
 	QDomDocument oldDoc;
 	QDomDocument::ParseResult parseResult = oldDoc.setContent(&newFzp);
-	if (!parseResult.operator bool()) {
+	if (!static_cast<bool>(parseResult)) {
 		QString logMessage = QString("Parse Error: %1 at line %2, column %3 in %4")
 								 .arg(parseResult.errorMessage)
 								 .arg(parseResult.errorLine)
