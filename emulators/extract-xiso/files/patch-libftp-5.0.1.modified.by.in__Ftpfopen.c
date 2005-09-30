--- libftp-5.0.1.modified.by.in/Ftpfopen.c.orig	Fri Sep 30 15:47:41 2005
+++ libftp-5.0.1.modified.by.in/Ftpfopen.c	Fri Sep 30 15:48:04 2005
@@ -60,6 +60,7 @@
 
 */
 
+#include <pthread.h>
 #include "FtpLibrary.h"
 
 
