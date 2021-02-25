--- include/com/sun/star/uno/Reference.h.orig	2020-11-27 17:16:53 UTC
+++ include/com/sun/star/uno/Reference.h
@@ -377,7 +377,7 @@ class SAL_DLLPUBLIC_RTTI Reference : public BaseRefere
 
         @return UNacquired interface pointer
     */
-    interface_type * SAL_CALL operator -> () const {
+    interface_type * SAL_CALL operator -> () const __attribute__ ((optnone)) {
         assert(_pInterface != NULL);
         return castFromXInterface(_pInterface);
     }
