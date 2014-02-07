--- engine/DefaultQHaccLoader.cpp.orig
+++ engine/DefaultQHaccLoader.cpp
@@ -22,6 +22,8 @@
 #include "QHacc.h"
 
 #include <sys/stat.h>
+#include <cstdlib>
+
 #include <QSqlQuery>
 #include <QSqlError>
 #include <QStringList>
