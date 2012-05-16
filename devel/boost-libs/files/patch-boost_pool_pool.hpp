--- boost/pool/pool.hpp.orig	2011-12-15 18:21:40.000000000 +0300
+++ boost/pool/pool.hpp	2011-12-15 18:22:05.000000000 +0300
@@ -346,7 +346,7 @@
       // For alignment reasons, this used to be defined to be lcm(requested_size, sizeof(void *), sizeof(size_type)),
       // but is now more parsimonious: just rounding up to the minimum required alignment of our housekeeping data
       // when required.  This works provided all alignments are powers of two.
-      size_type s = (std::max)(requested_size, min_alloc_size);
+      size_type s = (std::max)(requested_size, static_cast <size_type> (min_alloc_size));
       size_type rem = s % min_align;
       if(rem)
          s += min_align - rem;
