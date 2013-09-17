--- src/luabind/luabind/detail/call_member.hpp.orig	2010-01-04 02:08:15.000000000 +0300
+++ src/luabind/luabind/detail/call_member.hpp	2013-09-17 06:10:17.991226170 +0400
@@ -316,7 +316,8 @@
 
 #endif // LUABIND_CALL_MEMBER_HPP_INCLUDED
 
-#elif BOOST_PP_ITERATION_FLAGS() == 1
+#else
+#if BOOST_PP_ITERATION_FLAGS() == 1
 
 #define LUABIND_TUPLE_PARAMS(z, n, data) const A##n *
 #define LUABIND_OPERATOR_PARAMS(z, n, data) const A##n & a##n
@@ -361,3 +362,4 @@
 
 #endif
 
+#endif
