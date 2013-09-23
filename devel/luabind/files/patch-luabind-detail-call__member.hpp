--- luabind/detail/call_member.hpp.orig	2010-08-31 17:24:52.000000000 +0400
+++ luabind/detail/call_member.hpp	2013-09-23 22:19:01.134520448 +0400
@@ -316,7 +316,8 @@
 
 #endif // LUABIND_CALL_MEMBER_HPP_INCLUDED
 
-#elif BOOST_PP_ITERATION_FLAGS() == 1
+#else
+#if BOOST_PP_ITERATION_FLAGS() == 1
 
 #define LUABIND_TUPLE_PARAMS(z, n, data) const A##n *
 #define LUABIND_OPERATOR_PARAMS(z, n, data) const A##n & a##n
@@ -360,4 +361,5 @@
 #undef LUABIND_TUPLE_PARAMS
 
 #endif
+#endif
 
