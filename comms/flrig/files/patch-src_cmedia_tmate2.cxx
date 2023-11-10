--- src/cmedia/tmate2.cxx.orig	2022-03-21 23:27:19 UTC
+++ src/cmedia/tmate2.cxx
@@ -45,7 +45,9 @@
 #include <termios.h>
 #include <glob.h>
 #  ifndef __APPLE__
-#    include <error.h>
+#    ifndef __FreeBSD__
+#      include <error.h>
+#    endif
 #  endif
 #endif
 
