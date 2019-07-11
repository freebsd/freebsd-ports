--- src/sysc/utils/sc_string_view.h.orig	2019-07-11 10:13:48 UTC
+++ src/sysc/utils/sc_string_view.h
@@ -37,18 +37,18 @@
 
 #include <sysc/kernel/sc_cmnhdr.h>
 
-#if SC_CPLUSPLUS >= 201402L && defined(__has_include)
-#  if SC_CPLUSPLUS > 201402L && __has_include(<string_view>) /* since C++17 */
-#    define SC_STRING_VIEW_NS_ std
+//#if SC_CPLUSPLUS >= 201402L && defined(__has_include)
+//#  if SC_CPLUSPLUS > 201402L && __has_include(<string_view>) /* since C++17 */
+//#    define SC_STRING_VIEW_NS_ std
 #    include <string_view>
    /*  available in Library Fundamentals, ISO/IEC TS 19568:2015 */
-#  elif __has_include(<experimental/string_view>)
-#    define SC_STRING_VIEW_NS_ std::experimental
-#    include <experimental/string_view>
-#  endif
-#else
+//#  elif __has_include(<experimental/string_view>)
+//#    define SC_STRING_VIEW_NS_ std::experimental
+//#    include <experimental/string_view>
+//#  endif
+//#else
 // TODO: other ways to detect availability of std::(experimental::)string_view?
-#endif
+//#endif
 
 #ifndef SC_STRING_VIEW_NS_
 // fallback to (mostly compatible) implementation from Boost
