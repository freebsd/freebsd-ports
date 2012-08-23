--- ./dbaccess/source/ui/browser/sbagrid.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./dbaccess/source/ui/browser/sbagrid.cxx	2012-07-18 14:58:46.000000000 -0400
@@ -602,7 +602,7 @@
     Sequence< Type > aTypes = FmXGridPeer::getTypes();
     sal_Int32 nOldLen = aTypes.getLength();
     aTypes.realloc(nOldLen + 1);
-    aTypes.getArray()[nOldLen] = ::getCppuType( reinterpret_cast< Reference< ::com::sun::star::frame::XDispatch >* >(NULL) );
+    aTypes.getArray()[nOldLen] = ::getCppuType( static_cast< Reference< ::com::sun::star::frame::XDispatch >* >(0) );
 
     return aTypes;
 }
