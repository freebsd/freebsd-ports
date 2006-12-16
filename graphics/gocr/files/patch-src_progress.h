--- src/progress.h.orig	Sat Dec 16 16:12:16 2006
+++ src/progress.h	Sat Dec 16 16:12:46 2006
@@ -6,6 +6,8 @@
 #ifndef GOCR_PROGRESS_H
 #define GOCR_PROGRESS_H "Oct06"
 
+#include <time.h>
+
 /* initialization of progress output, fname="<fileID>","<filename>","-"  */
 int ini_progress(char *fname);
 
