Add missing include for unlink(2) call

--- simgear/misc/sg_path.cxx.orig	2020-05-22 20:11:33 UTC
+++ simgear/misc/sg_path.cxx
@@ -31,6 +31,7 @@
 
 #include <cstring>
 #include <stdio.h>
+#include <unistd.h>
 #include <sys/stat.h>
 #include <errno.h>
 #include <fstream>
