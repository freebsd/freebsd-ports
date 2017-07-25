--- include/audacity/Types.h.orig	2017-03-13 21:02:21 UTC
+++ include/audacity/Types.h
@@ -70,7 +70,7 @@ public:
    sampleCount ( int v ) : value { v } {}
    sampleCount ( unsigned v ) : value { v } {}
    sampleCount ( long v ) : value { v } {}
-   sampleCount ( unsigned long v ) : value { v } {}
+   sampleCount ( unsigned long v ) : value { static_cast<type>(v) } {}
 
    // Beware implicit conversions from floating point values!
    // Otherwise the meaning of binary operators with sampleCount change
