--- src/ugeneui/src/shtirlitz/Shtirlitz.cpp.orig
+++ src/ugeneui/src/shtirlitz/Shtirlitz.cpp
@@ -239,7 +239,10 @@ void Shtirlitz::getOsNameAndVersion( QSt
     version = QString::number(QSysInfo::MacintoshVersion);
 #elif defined(Q_OS_LINUX)
     name = "Linux";
-    Q_UNUSED(version);//no version is available :(
+    Q_UNUSED(version);	//no version is available :(
+#elif defined(Q_OS_FREEBSD)
+    name = "FreeBSD";
+    Q_UNUSED(version);	//no version is available :(
 #else
     name = "Other";
 #endif
