--- ./extensions/source/resource/ResourceIndexAccess.hxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./extensions/source/resource/ResourceIndexAccess.hxx	2012-07-18 15:17:25.000000000 -0400
@@ -58,7 +58,7 @@
             virtual ::sal_Bool SAL_CALL hasByName( const ::rtl::OUString& aName ) throw (::com::sun::star::uno::RuntimeException);
             // XElementAccess
             virtual ::com::sun::star::uno::Type SAL_CALL getElementType(  ) throw (::com::sun::star::uno::RuntimeException)
-                { return ::getCppuType(reinterpret_cast< ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface>*>(NULL)); };
+                { return ::getCppuType(static_cast< ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface>*>(0)); };
             virtual ::sal_Bool SAL_CALL hasElements(  ) throw (::com::sun::star::uno::RuntimeException)
                 { return static_cast<bool>(m_pResMgr.get()); };
 
