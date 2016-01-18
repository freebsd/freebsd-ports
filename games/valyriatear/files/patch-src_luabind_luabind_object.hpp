--- src/luabind/luabind/object.hpp.orig	2013-09-24 11:33:12 UTC
+++ src/luabind/luabind/object.hpp
@@ -546,6 +546,7 @@ namespace detail
       handle m_key;
   };
 
+#if BOOST_VERSION < 105700
 // Needed because of some strange ADL issues.
 
 #define LUABIND_OPERATOR_ADL_WKND(op) \
@@ -567,6 +568,7 @@ namespace detail
   LUABIND_OPERATOR_ADL_WKND(!=)
 
 #undef LUABIND_OPERATOR_ADL_WKND
+#endif
  
 } // namespace detail
 
