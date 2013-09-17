--- ./src/luabind/luabind/wrapper_base.hpp.orig	2010-01-04 02:08:15.000000000 +0300
+++ ./src/luabind/luabind/wrapper_base.hpp	2013-09-17 06:29:47.072226158 +0400
@@ -89,7 +89,8 @@
 
 #endif // LUABIND_WRAPPER_BASE_HPP_INCLUDED
 
-#elif BOOST_PP_ITERATION_FLAGS() == 1
+#else
+#if BOOST_PP_ITERATION_FLAGS() == 1
 
 #define LUABIND_TUPLE_PARAMS(z, n, data) const A##n *
 #define LUABIND_OPERATOR_PARAMS(z, n, data) const A##n & a##n
@@ -188,3 +189,4 @@
 #undef N
 
 #endif
+#endif
