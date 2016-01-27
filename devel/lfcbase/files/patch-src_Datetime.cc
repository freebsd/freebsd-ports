--- src/Datetime.cc.orig	2016-01-17 13:59:22 UTC
+++ src/Datetime.cc
@@ -17,6 +17,8 @@
 // Status: IMPLEMENTED
 ///////////////////////////////////////////////////////////////////////////////
 
+#include <config.h>
+
 #ifndef HAVE_STRPTIME
 #include "strptime.c"
 #endif
