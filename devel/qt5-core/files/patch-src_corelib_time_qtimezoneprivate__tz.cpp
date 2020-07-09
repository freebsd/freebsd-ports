--- src/corelib/time/qtimezoneprivate_tz.cpp.orig	2020-05-11 08:15:08 UTC
+++ src/corelib/time/qtimezoneprivate_tz.cpp
@@ -1153,6 +1153,25 @@ QByteArray QTzTimeZonePrivate::systemTimeZoneId() cons
         }
     }
 
+    // On some FreeBSD systems, /etc/localtime is a regular file while 
+    // the actual name is in /var/db/zoneinfo
+    if (ianaId.isEmpty()) {
+        QFile tzif(QStringLiteral("/var/db/zoneinfo"));
+        if (tzif.open(QIODevice::ReadOnly)) {
+            const int maximumTZNameLength = 256;
+            QByteArray tzcontents( tzif.read( maximumTZNameLength ) );
+            if (tzcontents.size() >= 2) {
+                // Shortest TZ would be UTC, or r/z, but there's special
+                // cases "GB" and "US"
+                const int newlineIndex = tzcontents.indexOf('\n');
+                if (newlineIndex < 0) // No newline in file
+                    ianaId = tzcontents;
+                if (newlineIndex > 2) // Newline, chop it off
+                    ianaId = tzcontents.left(newlineIndex);
+            }
+        }
+    }
+
     // Some systems (e.g. uClibc) have a default value for $TZ in /etc/TZ:
     if (ianaId.isEmpty()) {
         QFile zone(QStringLiteral("/etc/TZ"));
