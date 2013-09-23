--- luabind/detail/call_function.hpp.orig	2010-08-31 17:24:52.000000000 +0400
+++ luabind/detail/call_function.hpp	2013-09-23 22:18:38.767518606 +0400
@@ -323,7 +323,8 @@
 
 #endif // LUABIND_CALL_FUNCTION_HPP_INCLUDED
 
-#elif BOOST_PP_ITERATION_FLAGS() == 1
+#else
+#if BOOST_PP_ITERATION_FLAGS() == 1
 
 #define LUABIND_TUPLE_PARAMS(z, n, data) const A##n *
 #define LUABIND_OPERATOR_PARAMS(z, n, data) const A##n & a##n
@@ -440,4 +441,5 @@
 
 
 #endif
+#endif
 
