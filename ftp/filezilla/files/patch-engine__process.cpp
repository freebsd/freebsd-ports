--- src/engine/process.cpp.orig	2015-01-08 13:44:22.000000000 +0100
+++ src/engine/process.cpp	2015-01-08 13:44:48.000000000 +0100
@@ -1,5 +1,6 @@
 #include <filezilla.h>
 #include "process.h"
+#include <errno.h>
 
 #ifdef __WXMSW__
 
