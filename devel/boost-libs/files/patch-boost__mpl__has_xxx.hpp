--- boost/mpl/has_xxx.hpp.orig	2010-07-18 20:46:31.000000000 -0400
+++ boost/mpl/has_xxx.hpp	2014-05-06 17:10:52.000000000 -0400
@@ -341,7 +341,7 @@
       ) \
     /**/
 
-#   if !BOOST_MPL_HAS_XXX_NO_EXPLICIT_TEST_FUNCTION
+#   if !defined(BOOST_MPL_HAS_XXX_NO_EXPLICIT_TEST_FUNCTION) || !BOOST_MPL_HAS_XXX_NO_EXPLICIT_TEST_FUNCTION
 #     define BOOST_MPL_HAS_MEMBER_REJECT(args, member_macro) \
         template< typename V > \
         static boost::mpl::aux::no_tag \
@@ -354,7 +354,7 @@
       /**/
 #   endif
 
-#   if !BOOST_MPL_HAS_XXX_NO_WRAPPED_TYPES
+#   if !defined(BOOST_MPL_HAS_XXX_NO_WRAPPED_TYPES) || !BOOST_MPL_HAS_XXX_NO_WRAPPED_TYPES
 #     define BOOST_MPL_HAS_MEMBER_MULTI_ACCEPT(z, n, args) \
         template< typename V > \
         static boost::mpl::aux::yes_tag \
@@ -383,7 +383,7 @@
       /**/
 #   endif
 
-#   if !BOOST_MPL_HAS_XXX_NO_EXPLICIT_TEST_FUNCTION
+#   if !defined(BOOST_MPL_HAS_XXX_NO_EXPLICIT_TEST_FUNCTION) || !BOOST_MPL_HAS_XXX_NO_EXPLICIT_TEST_FUNCTION
 #     define BOOST_MPL_HAS_MEMBER_TEST(args) \
           sizeof(BOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args)< U >(0)) \
               == sizeof(boost::mpl::aux::yes_tag) \
@@ -456,7 +456,7 @@
       ) \
     /**/
 
-#   if BOOST_MPL_HAS_XXX_NEEDS_TEMPLATE_SFINAE
+#   if defined(BOOST_MPL_HAS_XXX_NEEDS_TEMPLATE_SFINAE) && BOOST_MPL_HAS_XXX_NEEDS_TEMPLATE_SFINAE
 
 #     if !defined(BOOST_MPL_HAS_XXX_NEEDS_NAMESPACE_LEVEL_SUBSTITUTE)
 #       if BOOST_WORKAROUND(BOOST_MSVC, <= 1400)
