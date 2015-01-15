--- src/core/StelFileMgr.cpp.orig	2014-10-11 11:24:38 UTC
+++ src/core/StelFileMgr.cpp
@@ -84,7 +84,23 @@ void StelFileMgr::init()
 		qWarning() << "WARNING: could not locate installation directory";
 	}
 
-	screenshotDir = QDesktopServices::storageLocation(QDesktopServices::PicturesLocation);
+	// Wasn't set path to screenshots directory via --screenshot-dir?
+	if (screenshotDir.isEmpty())
+	{
+		QString screenshotDirSuffix = "/Stellarium";
+		if (!QDesktopServices::storageLocation(QDesktopServices::PicturesLocation).isEmpty())
+			screenshotDir = QDesktopServices::storageLocation(QDesktopServices::PicturesLocation).append(screenshotDirSuffix);
+		else
+			screenshotDir = userDir.append(screenshotDirSuffix);
+	}
+	try
+	{
+		makeSureDirExistsAndIsWritable(screenshotDir);
+	}
+	catch (std::runtime_error &e)
+	{
+		qDebug("Error: cannot create screenshot directory: %s", e.what());
+	}
 }
 
 
