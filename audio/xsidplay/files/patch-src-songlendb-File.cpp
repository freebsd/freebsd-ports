--- src/songlendb/File.cpp.orig	Sun Mar  3 19:00:03 2002
+++ src/songlendb/File.cpp	Thu Feb 17 22:46:43 2005
@@ -29,6 +29,7 @@
 #endif
 using namespace std;
 
+#include <sys/types.h>
 #include "File.h"
 
 // String comparison functor for sort function.
@@ -126,9 +127,9 @@
     streampos fileLen = myIn.tellg();
 #endif
 #ifdef XSID_HAVE_NOTHROW
-    pDB = new(std::nothrow) char[fileLen+1L];
+    pDB = new(std::nothrow) char[(off_t)fileLen+1L];
 #else
-    pDB = new char[fileLen+1L];
+    pDB = new char[(off_t)fileLen+1L];
 #endif
     if ( pDB == 0 )
     {
