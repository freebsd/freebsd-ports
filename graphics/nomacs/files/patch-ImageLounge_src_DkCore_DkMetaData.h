--- ImageLounge/src/DkCore/DkMetaData.h.orig	2020-07-17 07:05:29 UTC
+++ ImageLounge/src/DkCore/DkMetaData.h
@@ -148,7 +148,7 @@ class DllCoreExport DkMetaDataT { (public)
 
 protected:
 	
-	Exiv2::Image::AutoPtr loadSidecar(const QString& filePath) const;
+	Exiv2::Image::UniquePtr loadSidecar(const QString& filePath) const;
 
 	enum {
 		not_loaded,
@@ -157,7 +157,7 @@ class DllCoreExport DkMetaDataT { (public)
 		dirty,
 	};
 
-	Exiv2::Image::AutoPtr mExifImg;
+	Exiv2::Image::UniquePtr mExifImg;
 	QString mFilePath;
 	QStringList mQtKeys;
 	QStringList mQtValues;
