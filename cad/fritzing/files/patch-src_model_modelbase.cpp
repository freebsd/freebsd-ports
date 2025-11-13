--- src/model/modelbase.cpp.orig	2025-04-02 10:33:24 UTC
+++ src/model/modelbase.cpp
@@ -895,7 +895,7 @@ ModelPart * ModelBase::createOldSchematicPartAux(Model
 	}
 	QDomDocument oldDoc;
 	QDomDocument::ParseResult parseResult = oldDoc.setContent(&newFzp);
-	if (!parseResult.operator bool()) {
+	if (!static_cast<bool>(parseResult)) {
 		QString logMessage = QString("Parse Error: %1 at line %2, column %3 in %4")
 								 .arg(parseResult.errorMessage)
 								 .arg(parseResult.errorLine)
