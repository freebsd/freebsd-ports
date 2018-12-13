--- main.cpp.orig	2013-10-15 07:01:22 UTC
+++ main.cpp
@@ -31,7 +31,6 @@ int main(int argc, char *argv[])
     app.setOrganizationDomain("qtrac.eu");
     app.setApplicationName("DiffPDF");
     app.setWindowIcon(QIcon(":/icon.png"));
-    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
 
     QTextStream out(stdout);
     QStringList args = app.arguments().mid(1);
