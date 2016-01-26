Fix build with Qt >= 5.5:

./WFPalette.hpp:53:1: error: unknown type name 'Q_DECLARE_METATYPE'
Q_DECLARE_METATYPE (WFPalette::Colours);
--- WFPalette.hpp.orig	2016-01-21 09:38:31 UTC
+++ WFPalette.hpp
@@ -4,6 +4,7 @@
 #include <QList>
 #include <QVector>
 #include <QColor>
+#include <QMetaType>
 
 class QString;
 
