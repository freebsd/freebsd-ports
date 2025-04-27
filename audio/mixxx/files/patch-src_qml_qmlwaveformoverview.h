Fix build with Qt >= 6.9.0

https://github.com/mixxxdj/mixxx/issues/14122

--- src/qml/qmlwaveformoverview.h.orig	2024-12-24 01:32:09 UTC
+++ src/qml/qmlwaveformoverview.h
@@ -58,7 +58,11 @@ class QmlWaveformOverview : public QQuickPaintedItem {
   signals:
     void playerChanged();
     void channelsChanged(mixxx::qml::QmlWaveformOverview::Channels channels);
+#if QT_VERSION >= QT_VERSION_CHECK(6, 9, 0)
+    void rendererChanged(Renderer renderer);
+#else
     void rendererChanged(mixxx::qml::QmlWaveformOverview::Renderer renderer);
+#endif
     void colorHighChanged(const QColor& color);
     void colorMidChanged(const QColor& color);
     void colorLowChanged(const QColor& color);
