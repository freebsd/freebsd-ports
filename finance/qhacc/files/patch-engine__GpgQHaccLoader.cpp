--- engine/GpgQHaccLoader.cpp.orig
+++ engine/GpgQHaccLoader.cpp
@@ -26,6 +26,7 @@
 #include <unistd.h>
 #include <iostream>
 #include <cstdio>
+#include <cerrno>
 
 #include <QFile>
 #include <QVariant>
