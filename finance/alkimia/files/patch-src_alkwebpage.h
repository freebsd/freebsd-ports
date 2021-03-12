Fix build when both the WEBKIT and WEBENGINE options are set to OFF.

/wrkdirs/usr/ports/finance/alkimia/work/alkimia-8.1.0/tools/onlinequoteseditor/mainwindow.cpp:52:28: error: member access into incomplete type 'const QUrl'
    d->urlLine->setText(url.toString());
                           ^
/usr/local/include/qt5/QtCore/qmetatype.h:2089:1: note: forward declaration of 'QUrl'
QT_FOR_EACH_STATIC_CORE_CLASS(QT_FORWARD_DECLARE_STATIC_TYPES_ITER)
^
/usr/local/include/qt5/QtCore/qmetatype.h:121:17: note: expanded from macro 'QT_FOR_EACH_STATIC_CORE_CLASS'
    F(QUrl, 17, QUrl) \
                ^
/wrkdirs/usr/ports/finance/alkimia/work/alkimia-8.1.0/tools/onlinequoteseditor/mainwindow.cpp:57:63: error: 'QUrl' is an incomplete type
    AlkOnlineQuotesProfileManager::instance().webPage()->load(QUrl(d->urlLine->text()), d->quotesWidget->acceptLanguage());
                                                              ^
/usr/local/include/qt5/QtCore/qmetatype.h:2089:1: note: forward declaration of 'QUrl'
QT_FOR_EACH_STATIC_CORE_CLASS(QT_FORWARD_DECLARE_STATIC_TYPES_ITER)
^
/usr/local/include/qt5/QtCore/qmetatype.h:121:17: note: expanded from macro 'QT_FOR_EACH_STATIC_CORE_CLASS'
    F(QUrl, 17, QUrl) \
                ^
2 errors generated.

--- src/alkwebpage.h.orig	2021-03-10 18:46:11 UTC
+++ src/alkwebpage.h
@@ -83,6 +83,7 @@ class ALK_EXPORT AlkWebPage : public QWebView (private
 
 #else
 
+#include <QUrl>
 #include <QWidget>
 
 /**
