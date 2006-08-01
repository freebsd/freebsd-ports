--- src/audiofile.cpp.orig	Mon Jul 31 17:13:02 2006
+++ src/audiofile.cpp	Mon Jul 31 17:13:20 2006
@@ -38,6 +38,8 @@
 // whether to permit this exception to apply to your modifications.
 // If you do not wish that, delete this exception notice.  
 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <cc++/config.h>
 #include <cc++/strchar.h>
 #include <cc++/export.h>
