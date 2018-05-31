--- src/cpp/desktop/DesktopDownloadItemHelper.cpp.orig	2018-05-30 17:56:35 UTC
+++ src/cpp/desktop/DesktopDownloadItemHelper.cpp
@@ -37,9 +37,9 @@ DownloadHelper::DownloadHelper(QWebEngin
    
    connect(item, &QWebEngineDownloadItem::finished,
            this, &DownloadHelper::onFinished);
-   
-   connect(item, &QWebEngineDownloadItem::isPausedChanged,
-           this, &DownloadHelper::onPausedChanged);
+   // exists from 5.10, while FreeBSD kept qt5-webengine at 5.9.5, the handler is empty anyway
+   //connect(item, &QWebEngineDownloadItem::isPausedChanged,
+   //        this, &DownloadHelper::onPausedChanged);
    
    connect(item, &QWebEngineDownloadItem::stateChanged,
            this, &DownloadHelper::onStateChanged);
