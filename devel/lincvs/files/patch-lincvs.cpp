--- src/lincvs.cpp.orig	Tue Feb 17 17:45:15 2004
+++ src/lincvs.cpp	Tue Feb 17 17:47:51 2004
@@ -2693,8 +2693,8 @@
    
    QString lang = QString(QTextCodec::locale()).left(2);  //maybe it's useful without left(2)
 
-   helpDir    = APPDIR + "/" + LC_HELP_DIR + "/" + LC_TRANSLATIONS_SUBDIR + "/" + lang;
-   helpDirDef = APPDIR + "/" + LC_HELP_DIR;
+   helpDir    = QString("%%PREFIX%%/share/doc/lincvs/") + LC_TRANSLATIONS_SUBDIR + "/" + lang;
+   helpDirDef = QString("%%PREFIX%%/share/doc/lincvs");
 
    filename = helpDir + tr("/README.html");
    f.setName(filename);
