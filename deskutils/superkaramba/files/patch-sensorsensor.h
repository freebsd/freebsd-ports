--- src/sensorsensor.h.orig    Fri Sep  5 15:00:20 2003
+++ src/sensorsensor.h Fri Sep  5 15:12:17 2003
@@ -32,6 +32,9 @@
     KShellProcess ksp;
 
     QMap<QString,QString> sensorMap;
+#ifdef __FreeBSD__
+    QMap<QString,QString> sensorMapBSD;
+#endif
     QString sensorResult;
 
 private slots:
