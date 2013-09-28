--- dumpmaps.cpp.orig	2013-09-28 17:26:05.102862359 +0200
+++ dumpmaps.cpp	2013-09-28 17:26:14.860038673 +0200
@@ -5,6 +5,7 @@
 #include <png.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <stdlib.h>
 
 class App : public Singleton < App > {
 public:
