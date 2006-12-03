--- src/ixlib_numeric.hh.orig	Thu Mar 22 16:16:25 2001
+++ src/ixlib_numeric.hh	Thu Nov 30 23:11:52 2006
@@ -67,56 +67,56 @@
 
 
 // Primitive inlines ---------------------------------------------------------
-  inline signed short ixion::sgn(signed long value) {
+  inline signed short sgn(signed long value) {
     return (value<0) ? -1 : ( (value>0) ? 1 : 0);
     }
   
   
   
   
-  inline bool ixion::getBit(unsigned long value,char bit) {
+  inline bool getBit(unsigned long value,char bit) {
     return (value >> bit) & 1;
     }
   
   
   
   
-  inline TUnsigned8 ixion::hiByte(TUnsigned16 value) {
+  inline TUnsigned8 hiByte(TUnsigned16 value) {
     return value >> 8;
     }
   
   
   
   
-  inline TUnsigned16 ixion::hiWord(TUnsigned32 value) {
+  inline TUnsigned16 hiWord(TUnsigned32 value) {
     return value >> 16;
     }
   
   
   
   
-  inline TUnsigned8 ixion::loByte(TUnsigned16 value) {
+  inline TUnsigned8 loByte(TUnsigned16 value) {
     return value & 0xff;
     }
   
   
   
   
-  inline TUnsigned16 ixion::loWord(TUnsigned32 value) {
+  inline TUnsigned16 loWord(TUnsigned32 value) {
     return value & 0xffff;
     }
   
   
   
   
-  inline TUnsigned16 ixion::makeWord(TUnsigned8 hi,TUnsigned8 lo) {
+  inline TUnsigned16 makeWord(TUnsigned8 hi,TUnsigned8 lo) {
     return (TUnsigned16) hi << 8 | lo;
     }
   
   
   
   
-  inline TUnsigned32 ixion::makeDWord(TUnsigned16 hi,TUnsigned16 lo) {
+  inline TUnsigned32 makeDWord(TUnsigned16 hi,TUnsigned16 lo) {
     return (TUnsigned32) hi << 16 | lo;
     }
   }
