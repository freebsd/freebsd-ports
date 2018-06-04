--- src/mdnsd-servicebrowser.cpp.orig	2018-05-05 12:57:24 UTC
+++ src/mdnsd-servicebrowser.cpp
@@ -100,7 +100,7 @@ void ServiceBrowser::startBrowse()
         fullType = d->m_subtype + "._sub." + d->m_type;
     }
     if (DNSServiceBrowse(&ref, 0, 0, fullType.toLatin1().constData(),
-                         domainToDNS(d->m_domain), query_callback, reinterpret_cast<void *>(d))
+                         domainToDNS(d->m_domain).constData(), query_callback, reinterpret_cast<void *>(d))
             == kDNSServiceErr_NoError) {
         d->setRef(ref);
     }
