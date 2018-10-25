--- src/drumkv1_jack.cpp.orig	2018-10-25 05:35:34 UTC
+++ src/drumkv1_jack.cpp
@@ -32,6 +32,7 @@
 #include <string.h>
 
 #include <math.h>
+#include <unistd.h>
 
 #include <QCoreApplication>
 #include <QDir>
