--- dm/dm.h.orig	Thu Jul 19 08:40:37 2001
+++ dm/dm.h	Sat Dec 21 08:58:14 2002
@@ -51,10 +51,11 @@
 // a bunch of hacks to select standard conforming iostream stuff if available
 // on the platform
 
-#if defined(WIN32) || (defined(sgi) && defined(_STANDARD_C_PLUS_PLUS)) || (defined(__GNUC__) && (__GNUC__>=2) && (__GNUC_MINOR__>=91))
+#if defined(WIN32) || (defined(sgi) && defined(_STANDARD_C_PLUS_PLUS)) || (defined(__GNUC__) && (__GNUC__>=2) && (__GNUC_MINOR__>=91)) || (defined(__GNUC__) && (__GNUC__>=3))
 #include <iostream>
 #include <iomanip>
 #include <fstream>
+using namespace std;
 #else
 #include <iostream.h>
 #include <iomanip.h>
