--- src/frameworks/UBPlatformUtils_linux.cpp.orig	2026-03-23 11:30:46 UTC
+++ src/frameworks/UBPlatformUtils_linux.cpp
@@ -43,7 +43,9 @@
 #include "core/UBSettings.h"
 #include "gui/UBMainWindow.h"
 
+#ifndef Q_OS_FREEBSD
 static OnboardListener* listener = nullptr;
+#endif
 
 void UBPlatformUtils::init()
 {
@@ -94,7 +96,7 @@ void UBPlatformUtils::hideFile(const QString &filePath
 void UBPlatformUtils::hideFile(const QString &filePath)
 {
     Q_UNUSED(filePath)
-    // TODO UB 4.x Not possible on Linux as such, the filename should have a . as first char in name
+    // TODO UB 4.x Not possible on FreeBSD and Linux as such, the filename should have a . as first char in name
 }
 
 void UBPlatformUtils::setFileType(const QString &filePath, unsigned long fileType)
@@ -102,7 +104,7 @@ void UBPlatformUtils::setFileType(const QString &fileP
     Q_UNUSED(filePath)
     Q_UNUSED(fileType)
 
-    // No fileType equivalent on Linux
+    // No fileType equivalent on FreeBSD and Linux
 }
 
 void UBPlatformUtils::fadeDisplayOut()
@@ -478,14 +480,14 @@ QString UBPlatformUtils::urlFromClipboard()
 {
     QString qsRet;
 
-    // Not used on Linux
+    // Not used on FreeBSD and Linux
 
     return qsRet;
 }
 
 void UBPlatformUtils::setFrontProcess()
 {
-    // not used in Linux
+    // not used in FreeBSD and Linux
 }
 
 
@@ -501,6 +503,10 @@ void UBPlatformUtils::showOSK(bool show)
 
 void UBPlatformUtils::showOSK(bool show)
 {
+#ifdef Q_OS_FREEBSD
+    Q_UNUSED(show);
+    // No on-screen keyboard support on FreeBSD
+#else
     if (show)
     {
         QDBusInterface dbus("org.onboard.Onboard", "/org/onboard/Onboard/Keyboard");
@@ -562,4 +568,5 @@ void OnboardListener::onboardPropertiesChanged(QString
             oskAction->trigger();
         }
     }
+#endif
 }
