--- src/LongUnion.h.orig	2024-06-16 17:07:29 UTC
+++ src/LongUnion.h
@@ -87,7 +87,7 @@ union LongUnion {
     struct {
         WordUnion LowWord;
         WordUnion HighWord;
-    } WordUnion;
+    } WordUnion2;
     uint8_t UBytes[4]; // seems to have the same code size as using struct UByte
     int8_t Bytes[4]; // Bytes[0] is LowByte
     uint16_t UWords[2];
@@ -122,7 +122,7 @@ union LongLongUnion {
         WordUnion MidLowWord;
         WordUnion MidHighWord;
         WordUnion HighWord;
-    } WordUnion;
+    } WordUnion3;
     struct {
         uint32_t LowLong;
         uint32_t HighLong;
@@ -134,7 +134,7 @@ union LongLongUnion {
     struct {
         LongUnion LowLong;
         LongUnion HighLong;
-    } LongUnion;
+    } LongUnion2;
     uint8_t UBytes[8]; // seems to have the same code size as using struct UByte
     int8_t Bytes[8];
     uint16_t UWords[4];
