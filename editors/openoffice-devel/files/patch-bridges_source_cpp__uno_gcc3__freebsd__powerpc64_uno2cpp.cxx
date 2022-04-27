--- bridges/source/cpp_uno/gcc3_freebsd_powerpc64/uno2cpp.cxx.orig	2019-09-17 22:55:10 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_powerpc64/uno2cpp.cxx
@@ -42,6 +42,14 @@ using namespace ::com::sun::star::uno;
 
 using namespace ::rtl;
 using namespace ::com::sun::star::uno;
+#ifdef __GLIBCXX__
+using CPPU_CURRENT_NAMESPACE::__cxa_exception;
+using CPPU_CURRENT_NAMESPACE::__cxa_get_globals;
+#else
+using __cxxabiv1::__cxa_exception;
+using __cxxabiv1::__cxa_current_primary_exception;
+using __cxxabiv1::__cxa_decrement_exception_refcount;
+#endif
 
 void MapReturn(long r3, double dret, typelib_TypeClass eTypeClass, void *pRegisterReturn)
 {
@@ -448,9 +456,18 @@ static void cpp_call(
 	}
  	catch (...)
  	{
+		__cxa_exception *header;
+#ifdef __GLIBCXX__
+		header = __cxa_get_globals()->caughtExceptions;
+#else
+		header = reinterpret_cast<__cxa_exception *>( __cxa_current_primary_exception() );
+		if (header) {
+			__cxa_decrement_exception_refcount( header );
+			header--;
+		}
+#endif
   		// fill uno exception
-		fillUnoException( CPPU_CURRENT_NAMESPACE::__cxa_get_globals()->caughtExceptions, 
-                                  *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+		CPPU_CURRENT_NAMESPACE::fillUnoException( header, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
         
 		// temporary params
 		for ( ; nTempIndizes--; )
