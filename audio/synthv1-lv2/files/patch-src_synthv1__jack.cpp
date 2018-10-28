--- src/synthv1_jack.cpp.orig	2018-10-28 21:16:24 UTC
+++ src/synthv1_jack.cpp
@@ -32,6 +32,7 @@
 #include <string.h>
 
 #include <math.h>
+#include <unistd.h>
 
 #include <QCoreApplication>
 #include <QDir>
