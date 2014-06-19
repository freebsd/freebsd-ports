--- src/mirall/mirallconfigfile.cpp.orig
+++ src/mirall/mirallconfigfile.cpp
@@ -359,11 +359,22 @@
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
 
 void MirallConfigFile::setSkipUpdateCheck( bool skip, const QString& connection )
