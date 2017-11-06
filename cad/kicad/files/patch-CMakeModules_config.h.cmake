--- CMakeModules/config.h.cmake.orig	2017-07-14 19:17:29 UTC
+++ CMakeModules/config.h.cmake
@@ -36,7 +36,7 @@
 #cmakedefine HAVE_ISO646_H
 
 #if defined( HAVE_ISO646_H )
-#include <iso646.h>
+#include <ciso646>
 #endif
 
 #if defined( HAVE_STRCASECMP )
