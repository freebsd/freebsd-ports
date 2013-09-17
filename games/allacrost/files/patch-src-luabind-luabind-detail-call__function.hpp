--- src/luabind/luabind/detail/call_function.hpp.orig	2010-01-04 02:08:15.000000000 +0300
+++ src/luabind/luabind/detail/call_function.hpp	2013-09-17 16:37:59.151519546 +0400
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
 
