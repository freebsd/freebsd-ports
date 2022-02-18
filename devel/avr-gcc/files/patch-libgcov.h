--- libgcc/libgcov.h~	2021-07-28 08:55:08.812308622 +0200
+++ libgcc/libgcov.h	2022-02-18 23:18:28.532448000 +0100
@@ -45,6 +45,8 @@
 #include "libgcc_tm.h"
 #include "gcov.h"
 
+#undef HAVE_SYS_MMAN_H // AVR environment doesn't have it
+
 #if HAVE_SYS_MMAN_H
 #include <sys/mman.h>
 #endif
