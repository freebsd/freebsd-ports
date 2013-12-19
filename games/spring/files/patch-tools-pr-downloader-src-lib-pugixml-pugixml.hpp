--- tools/pr-downloader/src/lib/pugixml/pugixml.hpp.orig	2013-12-06 06:19:54.039431635 +0400
+++ tools/pr-downloader/src/lib/pugixml/pugixml.hpp	2013-12-06 06:24:02.124415606 +0400
@@ -17,32 +17,9 @@
 #include "pugiconfig.hpp"
 
 #ifndef PUGIXML_NO_STL
-namespace std
-{
-	struct bidirectional_iterator_tag;
-
-#ifdef __SUNPRO_CC
-	// Sun C++ compiler has a bug which forces template argument names in forward declarations to be the same as in actual definitions
-	template <class _T> class allocator;
-	template <class _charT> struct char_traits;
-	template <class _charT, class _Traits> class basic_istream;
-	template <class _charT, class _Traits> class basic_ostream;
-	template <class _charT, class _Traits, class _Allocator> class basic_string;
-#else
-	// Borland C++ compiler has a bug which forces template argument names in forward declarations to be the same as in actual definitions
-	template <class _Ty> class allocator;
-	template <class _Ty> struct char_traits;
-	template <class _Elem, class _Traits> class basic_istream;
-	template <class _Elem, class _Traits> class basic_ostream;
-	template <class _Elem, class _Traits, class _Ax> class basic_string;
-#endif
-
-	// Digital Mars compiler has a bug which requires a forward declaration for explicit instantiation (otherwise type selection is messed up later, producing link errors)
-	// Also note that we have to declare char_traits as a class here, since it's defined that way
-#ifdef __DMC__
-	template <> class char_traits<char>;
-#endif
-}
+#   include <istream>
+#   include <ostream>
+#   include <string>
 #endif
 
 // Macro for deprecated features
