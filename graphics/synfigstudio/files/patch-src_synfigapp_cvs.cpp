--- src/synfigapp/cvs.cpp.orig	Sun Jun 24 17:35:08 2007
+++ src/synfigapp/cvs.cpp	Sun Jun 24 17:38:54 2007
@@ -39,6 +39,8 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <pthread.h>
+#include <fcntl.h>
 //#include <unistd.h>
 
 #include <cassert>
@@ -60,10 +62,10 @@
 #define HAVE_STRPTIME
 #endif
 
-#ifdef __APPLE__
+//#ifdef __APPLE__
 time_t _daylight_() { time_t t(time(0)); return localtime(&t)->tm_gmtoff; }
 #define daylight _daylight_()
-#endif
+//#endif
 
 /* === G L O B A L S ======================================================= */
 
