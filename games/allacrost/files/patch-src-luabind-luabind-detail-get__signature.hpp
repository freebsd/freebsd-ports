--- src/luabind/luabind/detail/get_signature.hpp.orig	2010-01-04 02:08:15.000000000 +0300
+++ src/luabind/luabind/detail/get_signature.hpp	2013-09-17 16:37:38.311587583 +0400
@@ -160,7 +160,8 @@
 
 #endif // LUABIND_GET_SIGNATURE_HPP_INCLUDED
 
-#elif BOOST_PP_ITERATION_FLAGS() == 1
+#else
+#if BOOST_PP_ITERATION_FLAGS() == 1
 
 	// member functions
 	template<class T, class C BOOST_PP_COMMA_IF(BOOST_PP_ITERATION()) BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(), class A)>
@@ -212,5 +213,6 @@
 	}
 
 #endif
+#endif
 
 #endif // LUABIND_NO_ERROR_CHECKING
