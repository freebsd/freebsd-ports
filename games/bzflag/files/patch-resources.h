--- src/bzflag/resources.h.orig	Sat Nov 23 15:18:38 2002
+++ src/bzflag/resources.h	Sat Nov 23 15:18:59 2002
@@ -20,12 +20,13 @@
 #include "common.h"
 #include "BzfString.h"
 
-#if defined(sun) || defined(macintosh)
-// solaris compiler doesn't like declaration of istream
+#if 1
 #include "bzfio.h"
 #else
 class istream;
 #endif
+
+using namespace std;
 
 class ResourceDatabase {
   public:
