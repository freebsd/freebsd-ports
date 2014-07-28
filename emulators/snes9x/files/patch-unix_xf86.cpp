diff -ru ../../work/release/unix/xf86.cpp ./unix/xf86.cpp
--- ../../work/release/unix/xf86.cpp	Tue Sep 22 06:36:50 1998
+++ ./unix/xf86.cpp	Wed Dec 29 01:54:04 1999
@@ -4,16 +4,20 @@
    Question/comments regarding this file only: maciej@imsa.edu
  */
 
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 //#define USE_XF86VIDMODE
 
+#ifdef __linux
 #include <asm/ioctls.h>
+#endif
+#include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/time.h>
+#ifdef __linux
 #include <linux/ioctl.h>
+#endif
 
 #include <fcntl.h>
-#include <sys/types.h>
 
 #include <string.h>
 #include <ctype.h>
@@ -833,4 +837,4 @@
 	ret = 1;
     return (ret);
 }
-#endif /* __linux */
+#endif /* __linux || __FreeBSD__ */
