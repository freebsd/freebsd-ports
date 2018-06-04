--- src/mdnsd-remoteservice.cpp.orig	2018-06-04 03:21:44 UTC
+++ src/mdnsd-remoteservice.cpp
@@ -82,8 +82,8 @@ void RemoteService::resolveAsync()
     d->m_resolved = false;
     //qDebug() << this << ":Starting resolve of : " << d->m_serviceName << " " << d->m_type << " " << d->m_domain << "\n";
     DNSServiceRef ref;
-    if (DNSServiceResolve(&ref, 0, 0, d->m_serviceName.toUtf8(), d->m_type.toLatin1().constData(),
-                          domainToDNS(d->m_domain), (DNSServiceResolveReply)resolve_callback, reinterpret_cast<void *>(d))
+    if (DNSServiceResolve(&ref, 0, 0, d->m_serviceName.toUtf8().constData(), d->m_type.toLatin1().constData(),
+                          domainToDNS(d->m_domain).constData(), (DNSServiceResolveReply)resolve_callback, reinterpret_cast<void *>(d))
             == kDNSServiceErr_NoError) {
         d->setRef(ref);
     }
