--- src/main.cpp.orig	Sun May 15 17:06:55 2005
+++ src/main.cpp	Wed May 18 21:58:58 2005
@@ -302,7 +302,7 @@
    if (pos > -1) lang.truncate(pos);
    if (bDebug) qDebug("LANG: " + lang);
 
-   QString messagesDir = APPDIR + "/" + LC_MESSAGES_DIR;
+   QString messagesDir = "/usr/local/share/lincvs/translation";
    bool qt_ts_found = false;
    QTranslator translator( 0 );
    QTranslator qtTranslator( 0 );
