--- libbase/tu_file.h.orig	2010-08-07 19:50:00.000000000 +0400
+++ libbase/tu_file.h	2010-10-01 20:49:40.000000000 +0400
@@ -12,6 +12,7 @@
 #include "dsodefs.h" // DSOEXPORT
 #include "utility.h"
 #include "IOChannel.h" // for inheritance
+#include <cstdio>
 
 
 namespace gnash {
