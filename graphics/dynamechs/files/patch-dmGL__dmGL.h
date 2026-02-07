--- dmGL/dmGL.h.orig	Sun Sep 14 21:05:00 2003
+++ dmGL/dmGL.h	Sun Sep 14 21:05:40 2003
@@ -44,13 +44,8 @@
 // a bunch of hacks to select standard conforming iostream stuff if available
 // on the platform
 
-#if defined(WIN32) || (defined(sgi) && defined(_STANDARD_C_PLUS_PLUS)) || (defined(__GNUC__) && (__GNUC__>=2) && (__GNUC_MINOR__>=91))
 #include <iostream>
 #include <iomanip>
-#else
-#include <iostream.h>
-#include <iomanip.h>
-#endif
 
 #include <GL/gl.h>
 #include <GL/glu.h>
@@ -68,9 +63,7 @@
 #endif
 
 // Use the std namespace. To do this we must first guarantee that it exists.
-#if defined(__sgi) || defined(__WIN32_) || defined(WIN32)
 namespace std {}
 using namespace std;
-#endif
 
 #endif
