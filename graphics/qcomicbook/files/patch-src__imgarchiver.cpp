--- src/imgarchiver.cpp.orig	Tue Aug 15 20:51:05 2006
+++ src/imgarchiver.cpp	Sun Aug 27 20:12:00 2006
@@ -13,6 +13,7 @@
 #include "imgarchiver.h"
 #include <qprocess.h>
 #include <qapplication.h>
+#include <unistd.h>
 
 using namespace QComicBook;
 
