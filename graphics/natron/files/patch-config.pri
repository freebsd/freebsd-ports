--- config.pri.orig	2017-10-03 16:22:18 UTC
+++ config.pri
@@ -0,0 +1,20 @@
+boost: LIBS += -lboost_serialization
+PKGCONFIG += expat
+PKGCONFIG += fontconfig
+cairo {
+        PKGCONFIG += cairo
+        LIBS -=  $$system(pkg-config --variable=libdir cairo)/libcairo.a
+}
+pyside {
+        PKGCONFIG -= pyside
+        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside)
+        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside)/QtCore
+        INCLUDEPATH += $$system(pkg-config --variable=includedir pyside)/QtGui
+        INCLUDEPATH += $$system(pkg-config --variable=includedir QtGui)
+        LIBS += -lpyside-python2.7
+}
+shiboken {
+        PKGCONFIG -= shiboken
+        INCLUDEPATH += $$system(pkg-config --variable=includedir shiboken)
+        LIBS += -lshiboken-python2.7
+}
