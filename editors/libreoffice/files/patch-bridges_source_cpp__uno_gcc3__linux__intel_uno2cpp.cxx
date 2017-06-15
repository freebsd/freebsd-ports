--- bridges/source/cpp_uno/gcc3_linux_intel/uno2cpp.cxx.orig	2016-10-28 14:50:26 UTC
+++ bridges/source/cpp_uno/gcc3_linux_intel/uno2cpp.cxx
@@ -198,10 +198,17 @@ static void cpp_call(
      catch (...)
      {
          // fill uno exception
+#ifdef _LIBCPP_VERSION
+         CPPU_CURRENT_NAMESPACE::fillUnoException(
+             reinterpret_cast< __cxxabiv1::__cxa_eh_globals * >(
+                 __cxxabiv1::__cxa_get_globals())->caughtExceptions,
+             *ppUnoExc, pThis->getBridge()->getCpp2Uno());
+#else
          fillUnoException(
              reinterpret_cast< CPPU_CURRENT_NAMESPACE::__cxa_eh_globals * >(
                  __cxxabiv1::__cxa_get_globals())->caughtExceptions,
              *ppUnoExc, pThis->getBridge()->getCpp2Uno());
+#endif
 
         // temporary params
         for ( ; nTempIndices--; )
