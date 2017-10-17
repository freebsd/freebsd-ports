--- gcin-qt5.h.orig	2017-09-21 12:57:19 UTC
+++ gcin-qt5.h
@@ -9,7 +9,7 @@ class QGcinPlatformInputContextPlugin : public QPlatfo
 {
     Q_OBJECT
 public:
-    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QPlatformInputContextFactoryInterface" FILE "gcin.json")
+    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QPlatformInputContextFactoryInterface.5.1" FILE "gcin.json")
     QStringList keys() const;
     QGcinPlatformInputContext *create(const QString& system, const QStringList& paramList);
 };
