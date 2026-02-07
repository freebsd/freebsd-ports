--- aquarobot/Gait.hpp.orig	2001-07-19 08:40:44.000000000 +0900
+++ aquarobot/Gait.hpp	2014-01-08 21:46:35.000000000 +0900
@@ -26,24 +26,17 @@
 #include <windows.h>
 #endif
 
-#if defined(WIN32) || (defined(sgi) && defined(_STANDARD_C_PLUS_PLUS)) || (defined(__GNUC__) && (__GNUC__>=2) && (__GNUC_MINOR__>=91))
 #include <iostream>
 #include <iomanip>
 #include <fstream>
-#else
-#include <iostream.h>
-#include <iomanip.h>
-#include <fstream.h>
-#endif
+using namespace std;
 
 #include <math.h>
 #include <stdlib.h>
 #include <stdio.h>
 
 // Use the std namespace. To do this we must first guarantee that it exists.
-#if defined(__sgi) || defined(__WIN32_) || defined(WIN32)
 namespace std {}
 using namespace std;
-#endif
 
 #endif
