--- lib/python/python.h.orig	Fri Sep  6 21:53:18 2002
+++ lib/python/python.h	Fri Sep  6 21:56:38 2002
@@ -12,13 +12,17 @@
 #include "debug.h"
 
 // I hate #define macros, seee if I can remove this
-#define STANDARD_LIBRARY_HAS_ITERATOR_TRAITS 1
+#define STANDARD_LIBRARY_HAS_RANDOM_ACCESS_ITERATOR 1
 #ifdef MS_WIN32
-#  undef STANDARD_LIBRARY_HAS_ITERATOR_TRAITS
-#  define STANDARD_LIBRARY_HAS_ITERATOR_TRAITS 0
+#  undef STANDARD_LIBRARY_HAS_RANDOM_ACCESS_ITERATOR
+#  define STANDARD_LIBRARY_HAS_RANDOM_ACCESS_ITERATOR 0
 #endif
 
-#if STANDARD_LIBRARY_HAS_ITERATOR_TRAITS
+#if defined (__GNUG__) && (__GNUG__ >= 3)
+#  undef STANDARD_LIBRARY_HAS_RANDOM_ACCESS_ITERATOR
+#endif
+
+#if STANDARD_LIBRARY_HAS_RANDOM_ACCESS_ITERATOR
 #  define random_access_iterator_parent(itemtype) std::random_access_iterator<itemtype, int>
 #else
 #  define random_access_iterator_parent(itemtype) std::iterator<std::random_access_iterator_tag,itemtype,int>
