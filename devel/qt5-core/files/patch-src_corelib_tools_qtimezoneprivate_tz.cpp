--- src/corelib/tools/qtimezoneprivate_tz.cpp.orig	2018-06-13 08:09:13.578248000 -0700
+++ src/corelib/tools/qtimezoneprivate_tz.cpp	2018-06-13 08:11:15.328743000 -0700
@@ -1072,6 +1072,17 @@ QByteArray QTzTimeZonePrivate::systemTim
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
