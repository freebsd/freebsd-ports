--- src/pin.cpp.orig	2026-09-29 13:36:55 UTC
+++ src/pin.cpp
@@ -951,10 +951,19 @@ class PinWindow final : public QWidget { (protected)
   // devices, the pointer-event and stillness paths still finish the drag.
   void openButtonWatch() {
     closeButtonWatch();
+#if defined(__FreeBSD__)
+    // No udev by-id symlinks here; watch every evdev node. Only BTN_LEFT
+    // events are acted on, so non-pointer devices are harmless.
+    QDir devices(QStringLiteral("/dev/input"));
+    const QStringList entries =
+        devices.entryList({QStringLiteral("event*")},
+                          QDir::System | QDir::Files | QDir::NoDotAndDotDot);
+#else
     QDir devices(QStringLiteral("/dev/input/by-id"));
     const QStringList entries =
         devices.entryList({QStringLiteral("*-event-mouse")},
                           QDir::System | QDir::Files | QDir::NoDotAndDotDot);
+#endif
     for (const QString &entry : entries) {
       const int fd =
           ::open(QFile::encodeName(devices.filePath(entry)).constData(),
