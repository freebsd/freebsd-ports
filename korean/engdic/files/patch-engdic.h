--- engdic.h.orig	1999-09-05 22:48:35.000000000 -0400
+++ engdic.h	2013-08-30 14:21:04.000000000 -0400
@@ -20,7 +20,7 @@
 */
 
 // Global value
-#define INSTALL_DIC_DATA_DIR "/usr/local/share/engdic"
+#define INSTALL_DIC_DATA_DIR "%%DATADIR%%"
 #define MAX_LENGTH 80 
 #define COLS_MAX 1024
 
