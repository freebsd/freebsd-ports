--- CMakeModules/config.h.cmake.orig	2018-07-13 19:53:52 UTC
+++ CMakeModules/config.h.cmake
@@ -36,7 +36,7 @@
 #cmakedefine HAVE_ISO646_H
 
 #if defined( HAVE_ISO646_H )
-#include <iso646.h>
+#include <ciso646>
 #endif
 
 #if !defined( HAVE_STRCASECMP )
