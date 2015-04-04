--- src/libsync/configfile.cpp.orig	2015-03-16 14:28:58 UTC
+++ src/libsync/configfile.cpp
@@ -383,11 +383,22 @@ bool ConfigFile::skipUpdateCheck( const 
     QString con( connection );
     if( connection.isEmpty() ) con = defaultConnection();
 
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
 
 void ConfigFile::setSkipUpdateCheck( bool skip, const QString& connection )
