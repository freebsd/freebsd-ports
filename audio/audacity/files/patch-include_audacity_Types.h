--- include/audacity/Types.h.orig	2018-10-01 14:07:33 UTC
+++ include/audacity/Types.h
@@ -311,7 +311,7 @@ class sampleCount (public)
    sampleCount ( long v ) : value { v } {}
 
    // unsigned long is 64 bit on some platforms.  Let it narrow.
-   sampleCount ( unsigned long v ) : value ( v ) {}
+   sampleCount ( unsigned long v ) : value { static_cast<type>(v) } {}
 
    // Beware implicit conversions from floating point values!
    // Otherwise the meaning of binary operators with sampleCount change
