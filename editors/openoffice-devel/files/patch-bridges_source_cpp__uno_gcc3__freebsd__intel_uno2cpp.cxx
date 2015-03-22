--- bridges/source/cpp_uno/gcc3_freebsd_intel/uno2cpp.cxx.orig	2014-09-19 17:51:13 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_intel/uno2cpp.cxx
@@ -305,7 +305,11 @@ static void cpp_call(
  	catch (...)
  	{
   		// fill uno exception
+#ifndef __GLIBCXX__
+		CPPU_CURRENT_NAMESPACE::fillUnoException( __cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+#else /* __GLIBCXX__ */
 		fillUnoException( CPPU_CURRENT_NAMESPACE::__cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+#endif /* __GLIBCXX__ */
         
 		// temporary params
 		for ( ; nTempIndizes--; )
