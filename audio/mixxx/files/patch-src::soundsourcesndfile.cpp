--- src/soundsourcesndfile.cpp.orig	Fri Jun 25 18:59:18 2004
+++ src/soundsourcesndfile.cpp	Fri Jun 25 19:03:08 2004
@@ -17,6 +17,8 @@
 #include "soundsourcesndfile.h"
 #include <qstring.h>
 #include "trackinfoobject.h"
+#define max(a,b)            (((a) > (b)) ? (a) : (b))
+#define min(a,b)            (((a) < (b)) ? (a) : (b))
 /*
   Class for reading files using libsndfile
 */
