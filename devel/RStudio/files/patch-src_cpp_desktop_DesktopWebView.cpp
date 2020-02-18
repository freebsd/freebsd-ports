--- src/cpp/desktop/DesktopWebView.cpp.orig	2020-01-23 23:30:24 UTC
+++ src/cpp/desktop/DesktopWebView.cpp
@@ -272,7 +272,7 @@ void WebView::contextMenuEvent(QContextMenuEvent* even
          
       case QWebEngineContextMenuData::MediaTypeAudio:
          
-#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
+#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0) && !defined(__FreeBSD__) // FreeBSD stayed with qt5-webengine-5.9.5_14 while Qt advanced to 5.12.0
          if (data.mediaFlags().testFlag(QWebEngineContextMenuData::MediaPaused))
             menu->addAction(label(tr("&Play")), [&]() { triggerPageAction(QWebEnginePage::ToggleMediaPlayPause); });
          else
@@ -289,7 +289,7 @@ void WebView::contextMenuEvent(QContextMenuEvent* even
          
       case QWebEngineContextMenuData::MediaTypeVideo:
          
-#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
+#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0) && !defined(__FreeBSD__) // FreeBSD stayed with qt5-webengine-5.9.5_14 while Qt advanced to 5.12.0
          if (data.mediaFlags().testFlag(QWebEngineContextMenuData::MediaPaused))
             menu->addAction(label(tr("&Play")), [&]() { triggerPageAction(QWebEnginePage::ToggleMediaPlayPause); });
          else
@@ -347,7 +347,7 @@ void WebView::contextMenuEvent(QContextMenuEvent* even
       menu->addAction(selectAll);
    }
    
-#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
+#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0) && !defined(__FreeBSD__) // FreeBSD stayed with qt5-webengine-5.9.5_14 while Qt advanced to 5.12.0
    menu->addSeparator();
    menu->addAction(label(tr("&Reload")), [&]() { triggerPageAction(QWebEnginePage::Reload); });
    menu->addAction(label(tr("I&nspect element")), [&]() {
