--- aquarobot/Gait.hpp.orig	Thu Jul 19 08:40:44 2001
+++ aquarobot/Gait.hpp	Sat Dec 21 08:57:01 2002
@@ -26,10 +26,11 @@
 #include <windows.h>
 #endif
 
-#if defined(WIN32) || (defined(sgi) && defined(_STANDARD_C_PLUS_PLUS)) || (defined(__GNUC__) && (__GNUC__>=2) && (__GNUC_MINOR__>=91))
+#if defined(WIN32) || (defined(sgi) && defined(_STANDARD_C_PLUS_PLUS)) || (defined(__GNUC__) && (__GNUC__>=2) && (__GNUC_MINOR__>=91)) || (defined(__GNUC__) && (__GNUC__>=3))
 #include <iostream>
 #include <iomanip>
 #include <fstream>
+using namespace std;
 #else
 #include <iostream.h>
 #include <iomanip.h>
