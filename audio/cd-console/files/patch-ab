--- cd_ll_bsd.cpp.orig	Sat Aug 25 14:09:00 2001
+++ cd_ll_bsd.cpp	Sat Oct 26 21:16:54 2002
@@ -10,7 +10,9 @@
 #include "cd_ll_bsd.h"
 
 // the cd-rom device file
-#define DEVICE "/dev/acd0c"
+#ifndef DEVICE
+#define DEVICE "/dev/cdrom"
+#endif
 
 cd_ll_bsd::cd_ll_bsd()
     : m_fd(-1)
