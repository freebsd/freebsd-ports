--- thinair/environ.h.orig	Wed Aug 16 17:08:27 2000
+++ thinair/environ.h	Wed Nov 19 21:54:56 2003
@@ -35,17 +35,20 @@
      #include <minmax.h>
   #endif
 
-  #if __GNUC__ >= 2 && __GNUC_MINOR__ >= 6 && defined( __cplusplus )
+  #if ((__GNUC__ == 2 && __GNUC_MINOR__ >= 6) || __GNUC__ > 2) && defined( __cplusplus )
      #define  _HAS_BOOL
      #define  _STRING_CLASS
-     #if __GNUC__ >= 2 && __GNUC_MINOR__ < 7
+     #define  _ANSI_CPP_HEADERS
+     #if __GNUC__ == 2 && __GNUC_MINOR__ < 7
        #define  _STRING_HEADER   <g++/String.h>
        #define  _STRING          String
      #else
        #define  _STRING_HEADER   <string>
        #define  _STRING          string
        #define  _DIFFERING_RETURNS_ALLOWED
+       #if __GNUC__ == 2
        #include <stl.h>
+       #endif
      #endif
      #define  _HAS_INT64
 
