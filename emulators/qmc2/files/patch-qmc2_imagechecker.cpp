Workaround where the LZMA headers #define False 0, while
parts of QtCore (the new qcborflags?) use False as an identifier.
--- qmc2/imagechecker.cpp.orig	2016-09-04 14:08:00 UTC
+++ qmc2/imagechecker.cpp
@@ -1,3 +1,4 @@
+#include <QtCore/QtCore>
 #include <QFileDialog>
 #include <QTest>
 #include <QMap>
