--- config.sh.orig	2018-03-04 01:48:31 UTC
+++ config.sh
@@ -101,7 +101,7 @@ if [ "$CPP" = "" ] ; then
     which g++ > /dev/null 2>&1 && CPP=g++
 fi
 
-MOC="moc"
+MOC?="moc"
 which moc-qt4 > /dev/null 2>&1 && MOC=moc-qt4
 
 echo "CC=$CC" >> makefile.opts
@@ -364,8 +364,8 @@ if [ "$WITHOUT_QT4" = "1" ] ; then
 else
     if which pkg-config > /dev/null 2>&1
     then
-        TMP_CFLAGS=$(pkg-config --cflags QtGui)
-        TMP_LDFLAGS="$(pkg-config --libs QtGui) -lX11"
+        TMP_CFLAGS="$(pkg-config --cflags QtGui) $(pkg-config --cflags x11)"
+        TMP_LDFLAGS="$(pkg-config --libs QtGui) $(pkg-config --libs x11)"
 
         echo "#include <QtGui>" > .tmp.cpp
         echo "int main(int argc, char *argv[]) { new QApplication(argc, argv) ; return 0; } " >> .tmp.cpp
