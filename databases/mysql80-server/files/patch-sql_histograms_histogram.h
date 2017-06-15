--- sql/histograms/histogram.h.orig	2017-01-05 16:18:44 UTC
+++ sql/histograms/histogram.h
@@ -111,7 +111,7 @@ public:
 
 // Typedefs.
 template<typename T>
-using value_map_allocator = Memroot_allocator<std::pair<T, ha_rows> >;
+using value_map_allocator = Memroot_allocator<std::pair<const T, ha_rows> >;
 
 template<typename T>
 using value_map_type = std::map<T, ha_rows, Histogram_comparator,
