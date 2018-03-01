--- include/audacity/Types.h.orig       2017-03-13 21:02:21 UTC
+++ include/audacity/Types.h
@@ -72,7 +72,7 @@
    sampleCount ( long v ) : value { v } {}
 
    // unsigned long is 64 bit on some platforms.  Let it narrow.
-   sampleCount ( unsigned long v ) : value ( v ) {}
+   sampleCount ( unsigned long v ) : value { static_cast<type>(v) } {}
 
    // Beware implicit conversions from floating point values!
    // Otherwise the meaning of binary operators with sampleCount change
