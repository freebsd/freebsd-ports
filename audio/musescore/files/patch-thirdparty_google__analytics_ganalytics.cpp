--- thirdparty/google_analytics/ganalytics.cpp.orig	2020-10-28 09:58:53 UTC
+++ thirdparty/google_analytics/ganalytics.cpp
@@ -381,7 +381,7 @@ QString GAnalytics::Private::getSystemInfo()
             .arg(QAndroidJniObject::getStaticObjectField<jstring>("android/os/Build", "ID").toString())
             .arg(QAndroidJniObject::getStaticObjectField<jstring>("android/os/Build", "BRAND").toString());
 }
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_UNIX)
 #include <sys/utsname.h>
 
 /**
