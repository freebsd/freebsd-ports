--- ./CMakeModules/config.h.cmake.orig	2010-04-13 20:11:02.000000000 +0200
+++ ./CMakeModules/config.h.cmake	2010-05-23 14:54:37.000000000 +0200
@@ -32,7 +32,7 @@
 #cmakedefine HAVE_ISO646_H
 
 #if defined( HAVE_ISO646_H )
-#include <iso646.h>
+#include <ciso646>
 #endif
 
 #cmakedefine HAVE_STRINGS_H
