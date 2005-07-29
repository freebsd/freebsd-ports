--- package/inc/ZipPackageFolder.hxx.orig	Thu Nov 15 21:01:49 2001
+++ package/inc/ZipPackageFolder.hxx	Wed Jun 12 23:10:42 2002
@@ -106,7 +106,7 @@
 
 	void doInsertByName ( ZipPackageEntry *pEntry, sal_Bool bSetParent )
 		throw(::com::sun::star::lang::IllegalArgumentException, ::com::sun::star::container::ElementExistException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException);
-	ContentInfo & doGetByName( const ::rtl::OUString& aName )
+	ZipContentInfo & doGetByName( const ::rtl::OUString& aName )
 		throw(::com::sun::star::container::NoSuchElementException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException);
 	static void copyZipEntry( ZipEntry &rDest, const ZipEntry &rSource);
 	static ::com::sun::star::uno::Sequence < sal_Int8 > static_getImplementationId()
