https://github.com/boostorg/wave/pull/31

--- boost/wave/cpplexer/re2clex/cpp_re.hpp.orig	2018-04-09 15:17:58 UTC
+++ boost/wave/cpplexer/re2clex/cpp_re.hpp
@@ -373,6 +373,9 @@ boost::wave::token_id scan(Scanner<Iterator> *s)
     string_type   rawstringdelim;         // for use with C++11 raw string literals
 
 // include the correct Re2C token definition rules
+#if (defined (__FreeBSD__) || defined (__DragonFly__) || defined (__OpenBSD__)) && defined (T_DIVIDE)
+#undef T_DIVIDE
+#endif
 #if BOOST_WAVE_USE_STRICT_LEXER != 0
 #include "strict_cpp_re.inc"
 #else
