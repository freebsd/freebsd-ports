--- src/plugins/android/androidrunnable.h.orig	2016-06-21 13:37:35 UTC
+++ src/plugins/android/androidrunnable.h
@@ -40,6 +40,8 @@ struct ANDROID_EXPORT AndroidRunnable
     QVector<QStringList> beforeStartADBCommands;
     QVector<QStringList> afterFinishADBCommands;
     QString deviceSerialNumber;
+
+    static void *staticTypeId;
 };
 
 inline bool operator==(const AndroidRunnable &r1, const AndroidRunnable &r2)
