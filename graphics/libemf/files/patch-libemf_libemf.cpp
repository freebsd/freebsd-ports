--- libemf/libemf.cpp.orig	2021-11-01 12:21:53 UTC
+++ libemf/libemf.cpp
@@ -72,8 +72,7 @@ namespace EMF {
     if ( not bigEndian() ) {
       return a;
     }
-#include <byteswap.h>
-    return bswap_32(a);
+    return __builtin_bswap32(a);
   }
 
   /*!
