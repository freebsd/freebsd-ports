--- ./src/corelib/tools/qdatetime.cpp.orig	2013-10-22 01:49:27.000000000 -0700
+++ ./src/corelib/tools/qdatetime.cpp	2013-11-04 16:56:16.155303199 -0800
@@ -2190,6 +2190,12 @@
         long offset;
         _get_timezone(&offset);
         return offset;
+#elif defined(Q_OS_FREEBSD)
+        time_t t;
+        struct tm *lt;
+        (void)time(&t);
+        lt = localtime(&t);
+        return -lt->tm_gmtoff;
 #else
         return timezone;
 #endif // Q_OS_WIN
@@ -2207,6 +2213,12 @@
         return QString::fromWCharArray(tzi.DaylightName);
     else
         return QString::fromWCharArray(tzi.StandardName);
+#elif defined(Q_OS_FREEBSD)
+    time_t t;
+    struct tm *lt;
+    (void)time(&t);
+    lt = localtime(&t);
+    return QString::fromLocal8Bit(lt->tm_zone);
 #else
     int isDst = (daylightStatus == QDateTimePrivate::DaylightTime) ? 1 : 0;
 #if defined(_MSC_VER) && _MSC_VER >= 1400
