--- src/foreign/zthread/include/zthread/Guard.h.orig      2011-12-02 18:02:37.253022000 +0100
+++ src/foreign/zthread/include/zthread/Guard.h    2013-01-18 19:08:14.000000000 +0100
@@ -108,7 +108,7 @@
   }

   template <class LockType>
-  static void createScope(LockHolder<LockType>& l, unsigned long ms) {
+  static bool createScope(LockHolder<LockType>& l, unsigned long ms) {

     if(Scope1::createScope(l, ms))
       if(!Scope2::createScope(l, ms)) {
