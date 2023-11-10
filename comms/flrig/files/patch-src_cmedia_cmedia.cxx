--- src/cmedia/cmedia.cxx.orig	2023-09-23 00:17:45 UTC
+++ src/cmedia/cmedia.cxx
@@ -42,7 +42,9 @@
 #include <termios.h>
 #include <glob.h>
 #  ifndef __APPLE__
-#    include <error.h>
+#    ifndef __FreeBSD__
+#      include <error.h>
+#    endif
 #  endif
 #endif
 
