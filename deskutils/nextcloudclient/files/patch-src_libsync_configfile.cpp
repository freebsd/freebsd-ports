--- src/libsync/configfile.cpp.orig	2017-12-20 15:03:02 UTC
+++ src/libsync/configfile.cpp
@@ -448,11 +448,22 @@ bool ConfigFile::skipUpdateCheck(const QString &connec
     if (connection.isEmpty())
         con = defaultConnection();
 
+#if 0
     QVariant fallback = getValue(QLatin1String(skipUpdateCheckC), con, false);
+#else
+    QVariant fallback = getValue(QLatin1String(skipUpdateCheckC), con, true);
+#endif
     fallback = getValue(QLatin1String(skipUpdateCheckC), QString(), fallback);
 
     QVariant value = getPolicySetting(QLatin1String(skipUpdateCheckC), fallback);
+#if 0
     return value.toBool();
+#else
+    if ( !value.toBool() )
+        qDebug() << "FreeBSD package disabled the UpdateCheck mechanism.";
+
+    return true;
+#endif
 }
 
 void ConfigFile::setSkipUpdateCheck(bool skip, const QString &connection)
