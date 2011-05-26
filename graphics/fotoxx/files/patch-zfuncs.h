--- zfuncs.h.orig	2011-02-28 17:04:24.000000000 +0100
+++ zfuncs.h	2011-05-25 17:50:21.000000000 +0200
@@ -36,7 +36,13 @@
 #include <signal.h>
 #include <execinfo.h>
 #include <locale.h>
-#include <sys/inotify.h>
+
+#ifdef __linux__
+   #include <sys/inotify.h>
+#elif defined(__FreeBSD__)
+   #include <sys/event.h>
+   #include <sys/types.h>
+#endif
 
 #define  int8   char                                                       //  number types
 #define  int16  short
