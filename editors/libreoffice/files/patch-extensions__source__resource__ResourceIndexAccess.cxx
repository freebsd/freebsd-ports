--- ./extensions/source/resource/ResourceIndexAccess.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./extensions/source/resource/ResourceIndexAccess.cxx	2012-07-18 15:15:23.000000000 -0400
@@ -94,7 +94,7 @@
             virtual ::com::sun::star::uno::Any SAL_CALL getByIndex( ::sal_Int32 Index ) throw (::com::sun::star::lang::IndexOutOfBoundsException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException);
             // XElementAccessBase
             virtual ::com::sun::star::uno::Type SAL_CALL getElementType(  ) throw (::com::sun::star::uno::RuntimeException)
-                { return ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)); };
+                { return ::getCppuType(static_cast< ::rtl::OUString*>(0)); };
     };
 
     class ResourceStringListIndexAccess : public ResourceIndexAccessBase
@@ -106,7 +106,7 @@
             virtual ::com::sun::star::uno::Any SAL_CALL getByIndex( ::sal_Int32 Index ) throw (::com::sun::star::lang::IndexOutOfBoundsException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException);
             // XElementAccessBase
             virtual ::com::sun::star::uno::Type SAL_CALL getElementType(  ) throw (::com::sun::star::uno::RuntimeException)
-                { return ::getCppuType(reinterpret_cast<Sequence<PropertyValue> * >(NULL)); };
+                { return ::getCppuType(static_cast<Sequence<PropertyValue> * >(0)); };
     };
 }
 
