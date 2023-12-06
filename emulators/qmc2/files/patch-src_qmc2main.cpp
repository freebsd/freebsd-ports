--- src/qmc2main.cpp.orig	2023-11-25 02:50:17 UTC
+++ src/qmc2main.cpp
@@ -2837,10 +2837,10 @@ void MainWindow::on_actionDocumentation_triggered(bool
 	if ( !qmc2DocBrowser ) {
 		qmc2DocBrowser = new DocBrowser(this);
 		qmc2DocBrowser->browser->spinBoxZoom->setValue(qmc2Config->value(QMC2_FRONTEND_PREFIX + "Layout/DocBrowser/Zoom", 100).toInt());
-		QString searchPath(qmc2Config->value(QMC2_FRONTEND_PREFIX + "FilesAndDirectories/DataDirectory").toString() + "doc/html/" + qmc2Config->value(QMC2_FRONTEND_PREFIX + "GUI/Language", "us").toString());
+		QString searchPath(qmc2Config->value(QMC2_FRONTEND_PREFIX + "FilesAndDirectories/DocumentationDirectory").toString() + "html/" + qmc2Config->value(QMC2_FRONTEND_PREFIX + "GUI/Language", "us").toString());
 		QFileInfo fi(searchPath + "/index.html");
 		if ( !fi.exists() || !fi.isFile() || fi.isSymLink() ) // fall back to US English if there's no language-specific index file
-			searchPath = qmc2Config->value(QMC2_FRONTEND_PREFIX + "FilesAndDirectories/DataDirectory").toString() + "doc/html/us";
+			searchPath = qmc2Config->value(QMC2_FRONTEND_PREFIX + "FilesAndDirectories/DocumentationDirectory").toString() + "html/us";
 #if defined(QMC2_OS_WIN)
 		QDir searchDir(searchPath);
 		QUrl docUrl("file:///" + searchDir.absolutePath() + "/index.html");
