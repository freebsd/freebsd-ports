--- XMill/PPMDI.cpp.orig	2016-07-26 12:48:05 UTC
+++ XMill/PPMDI.cpp
@@ -245,7 +245,7 @@ int PPMDI::uncompress(unsigned char *dst
 
 cleanup:
    *outused = j;
-   *inused = inlen - (int)endptr + (int)src;
+   *inused = inlen - (intptr_t)endptr + (intptr_t)src;
    return ret;
 }
  
