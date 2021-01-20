--- include/com/sun/star/uno/Reference.hxx.orig	2020-10-21 20:09:11 UTC
+++ include/com/sun/star/uno/Reference.hxx
@@ -91,7 +91,7 @@ inline XInterface * Reference< interface_type >::iquer
 
 template< class interface_type >
 inline interface_type * Reference< interface_type >::iset_throw(
-    interface_type * pInterface )
+    interface_type * pInterface ) __attribute__ ((optnone))
 {
     if (pInterface)
     {
@@ -104,7 +104,7 @@ inline interface_type * Reference< interface_type >::i
 }
 
 template< class interface_type >
-inline Reference< interface_type >::~Reference() COVERITY_NOEXCEPT_FALSE
+inline Reference< interface_type >::~Reference() COVERITY_NOEXCEPT_FALSE __attribute__ ((optnone))
 {
     if (_pInterface)
         _pInterface->release();
