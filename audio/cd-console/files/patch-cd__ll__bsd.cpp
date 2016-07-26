--- cd_ll_bsd.cpp.orig	2001-08-25 18:09:00 UTC
+++ cd_ll_bsd.cpp
@@ -10,7 +10,9 @@
 #include "cd_ll_bsd.h"
 
 // the cd-rom device file
-#define DEVICE "/dev/acd0c"
+#ifndef DEVICE
+#define DEVICE "/dev/cdrom"
+#endif
 
 cd_ll_bsd::cd_ll_bsd()
     : m_fd(-1)
