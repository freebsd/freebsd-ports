--- bridges/source/cpp_uno/gcc3_freebsd_intel/uno2cpp.cxx.orig	2019-09-17 22:55:10 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_intel/uno2cpp.cxx
@@ -44,9 +44,12 @@ using namespace ::com::sun::star::uno;
 using namespace ::rtl;
 using namespace ::com::sun::star::uno;
 #ifdef __GLIBCXX__
+using CPPU_CURRENT_NAMESPACE::__cxa_exception;
 using CPPU_CURRENT_NAMESPACE::__cxa_get_globals;
 #else
-using __cxxabiv1::__cxa_get_globals;
+using __cxxabiv1::__cxa_exception;
+using __cxxabiv1::__cxa_current_primary_exception;
+using __cxxabiv1::__cxa_decrement_exception_refcount;
 #endif
 
 namespace
@@ -313,8 +316,31 @@ static void cpp_call(
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
+			uint64_t exc_class = header->unwindHeader.exception_class
+					   & 0xffffffffffffff00;
+			if (exc_class != /* "GNUCC++" */ 0x474e5543432b2b00) {
+				// _Unwind_Exception was made __aligned__ which
+				// increased its size by 12 bytes.
+				header = reinterpret_cast<__cxa_exception *>(
+					reinterpret_cast<char *>( header ) - 12 );
+				exc_class = header->unwindHeader.exception_class
+					  & 0xffffffffffffff00;
+				if (exc_class != /* "GNUCC++" */ 0x474e5543432b2b00) {
+					header = nullptr;
+				}
+			}
+		}
+#endif
   		// fill uno exception
-		CPPU_CURRENT_NAMESPACE::fillUnoException( __cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+		CPPU_CURRENT_NAMESPACE::fillUnoException( header, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
         
 		// temporary params
 		for ( ; nTempIndizes--; )
