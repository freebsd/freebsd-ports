--- luabind/detail/policy.hpp.orig	2005-12-22 02:09:47.000000000 +0300
+++ luabind/detail/policy.hpp	2009-03-20 18:52:45.000000000 +0300
@@ -1276,7 +1276,8 @@
 
 namespace luabind { namespace
 {
-#if defined(__BORLANDC__) || (BOOST_VERSION >= 103400 && defined(__GNUC__))
+#if defined(__GNUC__) && \
+  (__GNUC__ * 100 + __GNUC_MINOR__ <= 400 || BOOST_VERSION <= 103401)
   static inline boost::arg<0> return_value()
   {
 	  return boost::arg<0>();
