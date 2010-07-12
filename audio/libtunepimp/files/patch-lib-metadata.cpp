--- lib/metadata.cpp.orig	2006-11-18 12:52:33.000000000 +0200
+++ lib/metadata.cpp	2010-06-07 10:43:10.556325912 +0300
@@ -26,6 +26,7 @@
 ----------------------------------------------------------------------------*/
 #include <math.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include "metadata.h"
 #include "../config.h"
 using namespace std;
@@ -35,6 +36,14 @@ extern "C"
    #include "astrcmp.h"
 }
 
+#ifndef min
+#define min(a,b) ((a) < (b) ? (a) : (b))
+#endif
+
+#ifndef max
+#define max(a,b) ((a) > (b) ? (a) : (b))
+#endif
+
 const int numAlbumTypeStrings = 11;
 const char *albumTypeStrings[] =
 {
