Fix the build with Qt >= 5.5:

src/qtlocalpeer.cpp:157:17: error: variable has incomplete type 'QDataStream'
    QDataStream ds(&socket);
                ^
/usr/local/include/qt5/QtCore/qglobal.h:570:7: note: forward declaration of 'QDataStream'
class QDataStream;
      ^
src/qtlocalpeer.cpp:177:17: error: variable has incomplete type 'QDataStream'
    QDataStream ds(socket);
                ^
/usr/local/include/qt5/QtCore/qglobal.h:570:7: note: forward declaration of 'QDataStream'
class QDataStream;
      ^
2 errors generated.
--- src/qtlocalpeer.cpp.orig	2016-01-21 08:48:24 UTC
+++ src/qtlocalpeer.cpp
@@ -40,6 +40,7 @@
 
 #include "qtlocalpeer.h"
 #include <QCoreApplication>
+#include <QDataStream>
 #include <QTime>
 
 #if defined(Q_OS_WIN)
