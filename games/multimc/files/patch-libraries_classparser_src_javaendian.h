--- libraries/classparser/src/javaendian.h.orig	2019-05-17 22:45:49 UTC
+++ libraries/classparser/src/javaendian.h
@@ -11,32 +11,32 @@ inline uint64_t bigswap(uint64_t x)
 {
     return x;
 }
-;
+
 inline uint32_t bigswap(uint32_t x)
 {
     return x;
 }
-;
+
 inline uint16_t bigswap(uint16_t x)
 {
     return x;
 }
-;
+
 inline int64_t bigswap(int64_t x)
 {
     return x;
 }
-;
+
 inline int32_t bigswap(int32_t x)
 {
     return x;
 }
-;
+
 inline int16_t bigswap(int16_t x)
 {
     return x;
 }
-;
+
 #else
 inline uint64_t bigswap(uint64_t x)
 {
