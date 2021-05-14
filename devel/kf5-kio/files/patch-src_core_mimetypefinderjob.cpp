--- src/core/mimetypefinderjob.cpp.orig	2021-05-14 15:38:26 UTC
+++ src/core/mimetypefinderjob.cpp
@@ -122,7 +122,9 @@ void KIO::MimeTypeFinderJobPrivate::statFile()
 {
     Q_ASSERT(m_mimeTypeName.isEmpty());
 
-    KIO::StatJob *job = KIO::statDetails(m_url, KIO::StatJob::SourceSide, KIO::StatBasic, KIO::HideProgressInfo);
+    static constexpr auto statFlags = KIO::StatBasic | KIO::StatResolveSymlink | KIO::StatMimeType;
+
+    KIO::StatJob *job = KIO::statDetails(m_url, KIO::StatJob::SourceSide, statFlags, KIO::HideProgressInfo);
     if (!m_authPrompts) {
         job->addMetaData(QStringLiteral("no-auth-prompt"), QStringLiteral("true"));
     }
@@ -146,6 +148,8 @@ void KIO::MimeTypeFinderJobPrivate::statFile()
         }
 
         const KIO::UDSEntry entry = job->statResult();
+
+        qCDebug(KIO_CORE) << "UDSEntry from StatJob in MimeTypeFinderJob" << entry;
 
         const QString localPath = entry.stringValue(KIO::UDSEntry::UDS_LOCAL_PATH);
         if (!localPath.isEmpty()) {
