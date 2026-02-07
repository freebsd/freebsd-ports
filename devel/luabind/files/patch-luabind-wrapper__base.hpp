--- luabind/wrapper_base.hpp.orig	2010-08-31 17:24:52.000000000 +0400
+++ luabind/wrapper_base.hpp	2013-09-23 22:18:10.975519864 +0400
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
