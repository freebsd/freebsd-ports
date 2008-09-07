--- src/lyrics.cpp.orig	2008-09-07 10:41:28.000000000 +0200
+++ src/lyrics.cpp	2008-09-07 10:41:51.000000000 +0200
@@ -19,7 +19,7 @@
  ***************************************************************************/
 
 #include "lyrics.h"
-#include <fcntl.h>
+#include <sys/stat.h>
 
 const string lyrics_folder = home_folder + "/" + ".lyrics";
 
