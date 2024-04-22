--- boost/boost_1_77_0/boost/mpl/aux_/integral_wrapper.hpp.orig	2021-08-05 09:42:13 UTC
+++ boost/boost_1_77_0/boost/mpl/aux_/integral_wrapper.hpp
@@ -56,7 +56,7 @@ struct AUX_WRAPPER_NAME
 // have to #ifdef here: some compilers don't like the 'N + 1' form (MSVC),
 // while some other don't like 'value + 1' (Borland), and some don't like
 // either
-#if BOOST_WORKAROUND(__EDG_VERSION__, <= 243)
+#if 1 //BOOST_WORKAROUND(__EDG_VERSION__, <= 243)
  private:
     BOOST_STATIC_CONSTANT(AUX_WRAPPER_VALUE_TYPE, next_value = BOOST_MPL_AUX_STATIC_CAST(AUX_WRAPPER_VALUE_TYPE, (N + 1)));
     BOOST_STATIC_CONSTANT(AUX_WRAPPER_VALUE_TYPE, prior_value = BOOST_MPL_AUX_STATIC_CAST(AUX_WRAPPER_VALUE_TYPE, (N - 1)));
