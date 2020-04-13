--- src/corelib/time/qtimezoneprivate_tz.cpp.orig	2019-11-01 21:30:15 UTC
+++ src/corelib/time/qtimezoneprivate_tz.cpp
@@ -1126,6 +1126,17 @@ QByteArray QTzTimeZonePrivate::systemTimeZoneId() cons
         }
     }
 
+    // On many FreeBSD systems, /etc/localtime is a regular file while the actual name is in /var/db/zoneinfo
+    if (ianaId.isEmpty()) {
+        QFile tzif(QStringLiteral("/var/db/zoneinfo"));
+        if (tzif.open(QIODevice::ReadOnly)) {
+            // TODO QTextStream inefficient, replace later
+            QTextStream ts(&tzif);
+            if (!ts.atEnd())
+                ianaId = ts.readLine().toUtf8();
+        }
+    }
+
     // On some Red Hat distros /etc/localtime is real file with name held in /etc/sysconfig/clock
     // in a line like ZONE="Europe/Oslo" or TIMEZONE="Europe/Oslo"
     if (ianaId.isEmpty()) {
