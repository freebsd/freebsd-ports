--- src/screen_utils.cxx.orig	2020-10-17 18:44:29 UTC
+++ src/screen_utils.cxx
@@ -31,6 +31,7 @@
 #include "WaitUserInput.hxx"
 #endif
 
+#include <errno.h>
 #include <string.h>
 
 void
