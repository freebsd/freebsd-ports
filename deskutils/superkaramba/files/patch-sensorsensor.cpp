--- src/sensorsensor.cpp.orig  Mon Apr 21 15:17:03 2003
+++ src/sensorsensor.cpp       Fri Sep  5 15:07:50 2003
@@ -12,6 +12,22 @@
 
 SensorSensor::SensorSensor( int interval ) : Sensor( interval )
 {
+#ifdef __FreeBSD__
+    sensorMapBSD["VCore 1"] = "VC0";
+    sensorMapBSD["VCore 2"] = "VC1";
+    sensorMapBSD["+3.3V"] = "V33";
+    sensorMapBSD["+5V"] = "V50P";
+    sensorMapBSD["+12V"] = "V12P";
+    sensorMapBSD["-12V"] = "V12N";
+    sensorMapBSD["-5V"] = "V50N";
+    sensorMapBSD["fan1"] = "FAN0";
+    sensorMapBSD["fan2"] = "FAN1";
+    sensorMapBSD["fan3"] = "FAN2";
+    sensorMapBSD["temp1"] = "TEMP0";
+    sensorMapBSD["temp2"] = "TEMP1";
+    sensorMapBSD["temp3"] = "TEMP2";
+#endif
+
     connect(&ksp, SIGNAL(receivedStdout(KProcess *, char *, int )),
             this,SLOT(receivedStdout(KProcess *, char *, int )));
     connect(&ksp, SIGNAL(processExited(KProcess *)),
@@ -36,8 +52,11 @@
     QStringList stringList = QStringList::split('\n',sensorResult);
     sensorResult = "";
     QStringList::Iterator it = stringList.begin();
+#ifdef __FreeBSD__
+    QRegExp rx( "^(\\S+)\\s+:\\s+[\\+\\-]?(\\d+\\.?\\d*)");
+#else
     QRegExp rx( "^(\\S+):\\s+[\\+\\-]?(\\d+\\.?\\d*)");
-
+#endif
     while( it != stringList.end())
     {
         rx.search( *it );
@@ -69,7 +88,12 @@
         {
             format = "%v";
         }
+
+#ifdef __FreeBSD__
+        format.replace( QRegExp("%v", false), sensorMap[sensorMapBSD[type]]);
+#else
         format.replace( QRegExp("%v", false), sensorMap[type]);
+#endif
         meter->setValue(format);
         ++lit;
     }
@@ -78,7 +102,11 @@
 void SensorSensor::update()
 {
     ksp.clearArguments();
+#ifdef __FreeBSD__
+    ksp << "mbmon -r -c 1";
+#else
     ksp << "sensors";
+#endif
     ksp.start( KProcess::NotifyOnExit,KProcIO::Stdout);
 }
 
