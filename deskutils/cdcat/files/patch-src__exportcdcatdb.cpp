--- src/exportcdcatdb.cpp.orig
+++ src/exportcdcatdb.cpp
@@ -30,6 +30,7 @@
 #include <QGridLayout>
 #include <QVBoxLayout>
 #include <iostream>
+#include <unistd.h>
 
 #include "icons.h"
 #include "cdcat.h"
