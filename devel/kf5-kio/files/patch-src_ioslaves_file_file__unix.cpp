--- src/ioslaves/file/file_unix.cpp.orig	2021-05-06 17:50:59 UTC
+++ src/ioslaves/file/file_unix.cpp
@@ -364,7 +364,7 @@ inline static time_t stat_mtime(QT_STATBUF &buf)
 }
 #endif
 
-static bool createUDSEntry(const QString &filename, const QByteArray &path, UDSEntry &entry, KIO::StatDetails details)
+static bool createUDSEntry(const QString &filename, const QByteArray &path, UDSEntry &entry, KIO::StatDetails details, const QUrl &url)
 {
     assert(entry.count() == 0); // by contract :-)
     int entries = 0;
@@ -539,7 +539,7 @@ static bool createUDSEntry(const QString &filename, co
 
     if (details & KIO::StatMimeType) {
         QMimeDatabase db;
-        entry.fastInsert(KIO::UDSEntry::UDS_MIME_TYPE, db.mimeTypeForFile(filename).name());
+        entry.fastInsert(KIO::UDSEntry::UDS_MIME_TYPE, db.mimeTypeForFile(url.toLocalFile()).name());
     }
 
     return true;
@@ -1186,7 +1186,7 @@ void FileProtocol::listDir(const QUrl &url)
             listEntry(entry);
 
         } else {
-            if (createUDSEntry(filename, QByteArray(ep->d_name), entry, details)) {
+            if (createUDSEntry(filename, QByteArray(ep->d_name), entry, details, url)) {
 #if HAVE_SYS_XATTR_H
                 if (isNtfsHidden(filename)) {
                     bool ntfsHidden = true;
@@ -1476,7 +1476,7 @@ void FileProtocol::stat(const QUrl &url)
     const KIO::StatDetails details = getStatDetails();
 
     UDSEntry entry;
-    if (!createUDSEntry(url.fileName(), _path, entry, details)) {
+    if (!createUDSEntry(url.fileName(), _path, entry, details, url)) {
         error(KIO::ERR_DOES_NOT_EXIST, path);
         return;
     }
