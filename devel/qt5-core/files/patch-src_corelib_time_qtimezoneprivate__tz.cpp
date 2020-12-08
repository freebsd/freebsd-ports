--- src/corelib/time/qtimezoneprivate_tz.cpp.orig	2020-09-12 18:44:11 UTC
+++ src/corelib/time/qtimezoneprivate_tz.cpp
@@ -1155,6 +1155,8 @@ class ZoneNameReader : public QObject (public)
             return m_name;
 
         m_name = etcLocalTime();
+        if (m_name.isEmpty())
+            m_name = varDBZoneinfo();
         if (!m_name.isEmpty()) {
             m_last = local;
             return m_name;
@@ -1203,6 +1205,27 @@ class ZoneNameReader : public QObject (public)
                 return path.midRef(index + zoneinfo.size()).toUtf8();
         } while (!path.isEmpty() && --iteration > 0);
 
+        return QByteArray();
+    }
+
+    static QByteArray varDBZoneinfo()
+    {
+        // On some FreeBSD systems, /etc/localtime is a regular file while 
+        // the actual name is in /var/db/zoneinfo
+        QFile tzif(QStringLiteral("/var/db/zoneinfo"));
+        if (tzif.open(QIODevice::ReadOnly)) {
+            const int maximumTZNameLength = 256;
+            QByteArray tzcontents( tzif.read( maximumTZNameLength ) );
+            if (tzcontents.size() >= 2) {
+                const int newlineIndex = tzcontents.indexOf('\n');
+                if (newlineIndex < 0) // No newline in file
+                    return tzcontents;
+                // Shortest TZ name in FreeBSD is "GB", "NZ" or "US"
+                if (newlineIndex >= 2) // Newline, chop it off
+                    return tzcontents.left(newlineIndex);
+                // Newline on position 0 or 1 is an invalid name
+            }
+        }
         return QByteArray();
     }
 
