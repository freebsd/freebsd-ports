--- src/main.cpp.orig	Tue Feb 17 17:28:10 2004
+++ src/main.cpp	Tue Feb 17 17:29:43 2004
@@ -225,7 +225,7 @@
    //install translator
    QString lang = QString(QTextCodec::locale());
    if (bDebug) qDebug("LANG: " + lang);
-   QString messagesDir = APPDIR + "/" + LC_MESSAGES_DIR;
+   QString messagesDir = "%%PREFIX%%/share/lincvs/translation";
 
    QTranslator translator( 0 );
    translator.load( lang, messagesDir );
