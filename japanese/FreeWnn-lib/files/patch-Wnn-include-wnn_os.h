Index: Wnn/include/wnn_os.h
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/include/wnn_os.h,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -d -u -I\$FreeBSD$ -w -r1.1.1.1 -r1.2
--- Wnn/include/wnn_os.h	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/include/wnn_os.h	2 Jan 2009 21:09:34 -0000	1.2
@@ -154,4 +154,5 @@
 		  unsigned char *euksc,
 		  int eusiz);		/* xutoj.c */
 
+#include "fake-rfc2553.h"
 #endif  /* WNN_OS_H */
