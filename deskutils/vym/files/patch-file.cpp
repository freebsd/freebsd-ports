--- file.cpp.orig	Thu Mar 23 13:38:54 2006
+++ file.cpp	Mon Sep  4 08:23:18 2006
@@ -5,6 +5,7 @@
 #include "file.h"
 #include "process.h"
 
+#include <unistd.h>
 
 QString maskPath(QString p)
 {
