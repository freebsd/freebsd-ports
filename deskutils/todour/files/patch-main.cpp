--- main.cpp.orig	2021-03-13 21:33:41 UTC
+++ main.cpp
@@ -5,6 +5,7 @@ int main(int argc, char *argv[])
 {
     QApplication a(argc, argv);
     MainWindow w;
+    a.setWindowIcon(QIcon(":/icons/newicon.png"));
     w.show();
     
     return a.exec();
