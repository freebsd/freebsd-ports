--- src/device/IDevice.cpp.orig	2016-06-04 19:56:45 UTC
+++ src/device/IDevice.cpp
@@ -22,7 +22,7 @@
 #include "gis/prj/IGisProject.h"
 #include "helpers/CSelectCopyAction.h"
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 #include <QtDBus>
 #endif
 
@@ -52,7 +52,7 @@ IDevice::~IDevice()
 
 void IDevice::mount(const QString& path)
 {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     QDBusMessage message = QDBusMessage::createMethodCall("org.freedesktop.UDisks2",path,"org.freedesktop.UDisks2.Filesystem","Mount");
     QVariantMap args;
     args.insert("options", "sync");
@@ -63,7 +63,7 @@ void IDevice::mount(const QString& path)
 
 void IDevice::umount(const QString &path)
 {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     QDBusMessage message = QDBusMessage::createMethodCall("org.freedesktop.UDisks2",path,"org.freedesktop.UDisks2.Filesystem","Unmount");
     QVariantMap args;
     message << args;
