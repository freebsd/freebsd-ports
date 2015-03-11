--- boost/thread/pthread/once_atomic.hpp.orig	2013-03-23 01:48:21 UTC
+++ boost/thread/pthread/once_atomic.hpp
@@ -115,7 +115,7 @@ namespace boost
 #endif
 
 
-#ifndef BOOST_NO_CXX11_VARIADIC_TEMPLATES
+#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
 
   template<typename Function, class ...ArgTypes>
   inline void call_once(once_flag& flag, BOOST_THREAD_RV_REF(Function) f, BOOST_THREAD_RV_REF(ArgTypes)... args)
