--- adplugdb/adplugdb.cpp.orig	Sun Aug  8 21:17:40 2004
+++ adplugdb/adplugdb.cpp	Sat May  7 06:16:26 2005
@@ -29,6 +29,7 @@
 #include <binfile.h>
 #include <string>
 #include <iostream>
+#include <unistd.h>
 
 #if defined(HAVE_SYS_TYPES_H) && defined(HAVE_SYS_STAT_H)
 #  if HAVE_SYS_TYPES_H
@@ -46,16 +47,6 @@
 #include "../src/adplug.h"
 #include "../src/silentopl.h"
 #include "../src/database.h"
-
-/*
- * Apple (OS X) and Sun systems declare getopt in unistd.h, other systems
- * (Linux) use getopt.h.
- */
-#if defined ( __APPLE__ ) || ( defined (__SVR4) && defined (__sun) )
-#	include <unistd.h>
-#else
-#	include "getopt.h"
-#endif
 
 /***** Defines *****/
 
