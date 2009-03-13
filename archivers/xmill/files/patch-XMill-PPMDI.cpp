--- XMill/PPMDI.cpp.orig	2009-03-13 19:12:05.000000000 +0100
+++ XMill/PPMDI.cpp	2009-03-13 19:12:29.000000000 +0100
@@ -245,7 +245,7 @@
 
 cleanup:
    *outused = j;
-   *inused = inlen - (int)endptr + (int)src;
+   *inused = inlen - (intptr_t)endptr + (intptr_t)src;
    return ret;
 }
  
