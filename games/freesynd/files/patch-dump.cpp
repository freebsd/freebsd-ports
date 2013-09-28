--- dump.cpp.orig	2013-09-28 17:25:56.240863970 +0200
+++ dump.cpp	2013-09-28 17:25:38.414006911 +0200
@@ -5,6 +5,7 @@
 #include <png.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <stdlib.h>
 
 class App : public Singleton < App > {
 public:
