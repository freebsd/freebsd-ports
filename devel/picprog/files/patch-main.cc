--- main.cc.orig	Tue Nov 19 12:50:51 2002
+++ main.cc	Tue Nov 19 12:51:11 2002
@@ -32,6 +32,7 @@
 
 #include <sysexits.h>
 #include <unistd.h>
+#define HAVE_DECL_GETOPT 1
 #include <getopt.h>
 
 #include "hexfile.h"
