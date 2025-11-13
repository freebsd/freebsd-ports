--- src/fapplication.cpp.orig	2025-04-02 10:33:24 UTC
+++ src/fapplication.cpp
@@ -895,19 +895,7 @@ bool FApplication::loadReferenceModel(const QString & 
 
 	QFileInfo info(dbPath);
 	bool dbExists = (info.size() > 0) && !fullLoad;
-
-	QString sha;
-	if (!dbExists) {
-		// fullLoad == true means we are creating the parts database
-		// so get the sha for last commit of the parts folder and store it in the database
-		// this sha will be used to determine whether the user's parts folder can be updated from the remote repo
-		sha = PartsChecker::getSha(dir.absolutePath());
-		if (sha.isEmpty()) {
-			DebugDialog::debug(QString("1.6 SHA empty"));
-			return false;
-		}
-		referenceModel->setSha(sha);
-	}
+	referenceModel->setSha("");
 
 	// loads local parts, resource parts, and any other parts in files not in the db--these part override db parts with the same moduleID
 	QString db = databaseName;
