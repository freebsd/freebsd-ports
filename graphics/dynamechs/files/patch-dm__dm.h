--- dm/dm.h.orig	Wed Jul 18 18:40:37 2001
+++ dm/dm.h	Sat Sep 13 11:00:02 2003
@@ -48,18 +48,9 @@
 #include <windows.h>
 #endif
 
-// a bunch of hacks to select standard conforming iostream stuff if available
-// on the platform
-
-#if defined(WIN32) || (defined(sgi) && defined(_STANDARD_C_PLUS_PLUS)) || (defined(__GNUC__) && (__GNUC__>=2) && (__GNUC_MINOR__>=91))
 #include <iostream>
 #include <iomanip>
 #include <fstream>
-#else
-#include <iostream.h>
-#include <iomanip.h>
-#include <fstream.h>
-#endif
 
 #include <math.h>
 #include <stdlib.h>
@@ -102,10 +93,8 @@
 };
 
 // Use the std namespace. To do this we must first guarantee that it exists.
-#if defined(__sgi) || defined(__WIN32_) || defined(WIN32)
 namespace std {}
 using namespace std;
-#endif
 
 //----------------------------------------------------------------------------
 inline void normalizeQuat(Quaternion quat)
