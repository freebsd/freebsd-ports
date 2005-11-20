--- src/Network/ATC-Inputs.cxx.orig	Sun Nov 20 19:02:57 2005
+++ src/Network/ATC-Inputs.cxx	Sun Nov 20 19:05:33 2005
@@ -32,7 +32,11 @@
 #  include <sys/stat.h>
 #  include <fcntl.h>
 #  include <unistd.h>
-#  include <istream>
+#  ifdef SG_HAVE_STD_INCLUDES
+#    include <istream>
+#  else
+#    include <istream.h>
+#  endif
 #endif
 
 #include <errno.h>
