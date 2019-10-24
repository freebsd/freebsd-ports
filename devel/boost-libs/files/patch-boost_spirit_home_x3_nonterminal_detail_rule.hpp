https://github.com/boostorg/spirit/pull/549

--- boost/spirit/home/x3/nonterminal/detail/rule.hpp.orig	2019-08-14 12:03:34 UTC
+++ boost/spirit/home/x3/nonterminal/detail/rule.hpp
@@ -20,6 +20,8 @@
 #include <boost/spirit/home/x3/nonterminal/simple_trace.hpp>
 #endif
 
+#include <type_traits>
+
 namespace boost { namespace spirit { namespace x3
 {
     template <typename ID>
@@ -191,7 +193,7 @@ namespace boost { namespace spirit { namespace x3 { na
             typedef
                 decltype(parse_rule(
                     rule<ID, Attribute>(), first, last
-                  , make_unique_context<ID>(rhs, context), attr))
+                  , make_unique_context<ID>(rhs, context), std::declval<Attribute&>()))
             parse_rule_result;
 
             // If there is no BOOST_SPIRIT_DEFINE for this rule,
