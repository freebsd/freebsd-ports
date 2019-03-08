--- src/cpp/desktop/DesktopWebView.cpp.orig	2019-02-18 00:53:59 UTC
+++ src/cpp/desktop/DesktopWebView.cpp
@@ -257,7 +257,7 @@ void WebView::contextMenuEvent(QContextM
          
       case QWebEngineContextMenuData::MediaTypeAudio:
          
-#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
+#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0) && !defined(__FreeBSD__) // FreeBSD stayed with qt5-webengine-5.9.5_14 while Qt advanced to 5.12.0
          if (data.mediaFlags().testFlag(QWebEngineContextMenuData::MediaPaused))
             menu->addAction(label(tr("&Play")), [&]() { triggerPageAction(QWebEnginePage::ToggleMediaPlayPause); });
          else
@@ -274,7 +274,7 @@ void WebView::contextMenuEvent(QContextM
          
       case QWebEngineContextMenuData::MediaTypeVideo:
          
-#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
+#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0) && !defined(__FreeBSD__) // FreeBSD stayed with qt5-webengine-5.9.5_14 while Qt advanced to 5.12.0
          if (data.mediaFlags().testFlag(QWebEngineContextMenuData::MediaPaused))
             menu->addAction(label(tr("&Play")), [&]() { triggerPageAction(QWebEnginePage::ToggleMediaPlayPause); });
          else
@@ -332,7 +332,7 @@ void WebView::contextMenuEvent(QContextM
       menu->addAction(selectAll);
    }
    
-#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
+#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0) && !defined(__FreeBSD__) // FreeBSD stayed with qt5-webengine-5.9.5_14 while Qt advanced to 5.12.0
    menu->addSeparator();
    menu->addAction(label(tr("&Reload")), [&]() { triggerPageAction(QWebEnginePage::Reload); });
    menu->addAction(label(tr("I&nspect element")), [&]() {
