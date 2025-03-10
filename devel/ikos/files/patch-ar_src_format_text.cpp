- workaround the potential problem in boost: /usr/local/include/boost/move/adl_move_swap.hpp:190:15: error: no member named 'swap' in namespace 'std'

--- ar/src/format/text.cpp.orig	2025-01-08 22:27:38 UTC
+++ ar/src/format/text.cpp
@@ -41,6 +41,8 @@
  *
  ******************************************************************************/
 
+#include <algorithm>
+
 #include <boost/container/flat_set.hpp>
 
 #include <ikos/ar/format/text.hpp>
