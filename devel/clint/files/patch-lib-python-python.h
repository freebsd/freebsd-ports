--- lib/python/python.h.orig	2001-04-16 21:53:21.000000000 +0200
+++ lib/python/python.h	2007-11-03 16:31:32.000000000 +0100
@@ -3,22 +3,42 @@
 
 #pragma interface
 
+#include <ctype.h>
+#undef isalnum
+#undef isalpha
+#undef iscntrl
+#undef isdigit
+#undef isgraph
+#undef islower
+#undef isprint
+#undef ispunct
+#undef isspace
+#undef isupper
+#undef isxdigit
+#undef tolower
+#undef toupper
+#include <iostream>
+
 #include <Python.h>
 #include <string>
 #include <iterator>
 #include <utility>
-#include <strstream>
+#include <sstream>
 #include "exceptions.h"
 #include "debug.h"
 
 // I hate #define macros, seee if I can remove this
-#define STANDARD_LIBRARY_HAS_ITERATOR_TRAITS 1
+#define STANDARD_LIBRARY_HAS_RANDOM_ACCESS_ITERATOR 1
 #ifdef MS_WIN32
-#  undef STANDARD_LIBRARY_HAS_ITERATOR_TRAITS
-#  define STANDARD_LIBRARY_HAS_ITERATOR_TRAITS 0
+#  undef STANDARD_LIBRARY_HAS_RANDOM_ACCESS_ITERATOR
+#  define STANDARD_LIBRARY_HAS_RANDOM_ACCESS_ITERATOR 0
+#endif
+
+#if defined (__GNUG__) && (__GNUG__ >= 3)
+#  undef STANDARD_LIBRARY_HAS_RANDOM_ACCESS_ITERATOR
 #endif
 
-#if STANDARD_LIBRARY_HAS_ITERATOR_TRAITS
+#if STANDARD_LIBRARY_HAS_RANDOM_ACCESS_ITERATOR
 #  define random_access_iterator_parent(itemtype) std::random_access_iterator<itemtype, int>
 #else
 #  define random_access_iterator_parent(itemtype) std::iterator<std::random_access_iterator_tag,itemtype,int>
