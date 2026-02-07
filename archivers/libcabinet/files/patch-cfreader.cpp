--- cfreader.cpp.orig	1999-10-24 06:13:29 UTC
+++ cfreader.cpp
@@ -22,7 +22,7 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
-#include <fstream.h>
+#include <fstream>
 #include "darray.h"
 #include "cffile.h"
 #include "cftypes.h"
@@ -31,6 +31,8 @@
 #include "cfheader.h"
 #include "cfreader.h"
 
+using std::ios;
+
 ////////////////////////////////////////****************************************
 
 int cabinet_reader::open(const char* fname)
