--- bridges/source/cpp_uno/gcc3_freebsd_x86-64/uno2cpp.cxx.orig	2014-09-19 10:51:13.000000000 -0700
+++ bridges/source/cpp_uno/gcc3_freebsd_x86-64/uno2cpp.cxx	2015-03-13 09:48:24.000000000 -0700
@@ -446,7 +446,11 @@
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
