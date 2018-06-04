--- src/mdnsd-publicservice.cpp.orig	2018-05-05 12:57:24 UTC
+++ src/mdnsd-publicservice.cpp
@@ -160,7 +160,7 @@ void PublicService::publishAsync()
     TXTRecordCreate(&txt, 0, 0);
     QMap<QString, QByteArray>::ConstIterator itEnd = d->m_textData.cend();
     for (QMap<QString, QByteArray>::ConstIterator it = d->m_textData.cbegin(); it != itEnd; ++it) {
-        if (TXTRecordSetValue(&txt, it.key().toUtf8(), it.value().length(), it.value()) != kDNSServiceErr_NoError) {
+        if (TXTRecordSetValue(&txt, it.key().toUtf8().constData(), it.value().length(), it.value().data()) != kDNSServiceErr_NoError) {
             TXTRecordDeallocate(&txt);
             emit published(false);
             return;
@@ -171,7 +171,7 @@ void PublicService::publishAsync()
     Q_FOREACH (const QString &subtype, d->m_subtypes) {
         fullType += ',' + subtype;
     }
-    if (DNSServiceRegister(&ref, 0, 0, d->m_serviceName.toUtf8(), fullType.toLatin1().constData(), domainToDNS(d->m_domain), NULL,
+    if (DNSServiceRegister(&ref, 0, 0, d->m_serviceName.toUtf8().constData(), fullType.toLatin1().constData(), domainToDNS(d->m_domain).constData(), NULL,
                            htons(d->m_port), TXTRecordGetLength(&txt), TXTRecordGetBytesPtr(&txt), publish_callback,
                            reinterpret_cast<void *>(d)) == kDNSServiceErr_NoError) {
         d->setRef(ref);
