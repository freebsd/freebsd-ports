--- src/corelib/time/qtimezoneprivate_tz.cpp.orig	2025-05-14 09:43:58 UTC
+++ src/corelib/time/qtimezoneprivate_tz.cpp
@@ -1313,8 +1313,16 @@ class ZoneNameReader (public)
         const StatIdent local = identify("/etc/localtime");
         const StatIdent tz = identify("/etc/TZ");
         const StatIdent timezone = identify("/etc/timezone");
+        const StatIdent db_zoneinfo = identify("/var/db/zoneinfo");
         if (!m_name.isEmpty() && m_last.isValid()
-            && (m_last == local || m_last == tz || m_last == timezone)) {
+            && (m_last == local || m_last == tz || m_last == timezone || m_last == db_zoneinfo)) {
+            return m_name;
+        }
+
+        // FreeBSD usually has /var/db/zoneinfo with the name of the TZ
+        m_name = etcContent(QStringLiteral("/var/db/zoneinfo"));
+        if (!m_name.isEmpty()) {
+            m_last = db_zoneinfo;
             return m_name;
         }
 
