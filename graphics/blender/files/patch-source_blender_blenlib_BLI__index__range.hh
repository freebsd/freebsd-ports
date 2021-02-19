--- source/blender/blenlib/BLI_index_range.hh.orig	2021-01-23 14:11:28 UTC
+++ source/blender/blenlib/BLI_index_range.hh
@@ -58,11 +58,6 @@

 #include "BLI_utildefines.h"

-/* Forward declare tbb::blocked_range for conversion operations. */
-namespace tbb {
-template<typename Value> class blocked_range;
-}
-
 namespace blender {

 template<typename T> class Span;
@@ -84,11 +79,6 @@ class IndexRange {
   {
     BLI_assert(start >= 0);
     BLI_assert(size >= 0);
-  }
-
-  template<typename T>
-  IndexRange(const tbb::blocked_range<T> &range) : start_(range.begin()), size_(range.size())
-  {
   }

   class Iterator {
