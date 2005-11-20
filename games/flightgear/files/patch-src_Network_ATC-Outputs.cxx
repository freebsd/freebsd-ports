--- src/Network/ATC-Outputs.cxx.orig	Sun Nov 20 19:14:22 2005
+++ src/Network/ATC-Outputs.cxx	Sun Nov 20 19:14:47 2005
@@ -32,7 +32,6 @@
 #  include <sys/stat.h>
 #  include <fcntl.h>
 #  include <unistd.h>
-#  include <ostream>
 #endif
 
 #include <errno.h>
@@ -47,6 +46,7 @@
 
 #include "ATC-Outputs.hxx"
 
+SG_USING_STD(ostream);
 SG_USING_STD(string);
 
 
