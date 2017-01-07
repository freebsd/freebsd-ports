--- sql/histograms/singleton.h.orig	2017-01-05 16:21:18 UTC
+++ sql/histograms/singleton.h
@@ -89,7 +89,7 @@ private:
 
   /// The buckets for this histogram [key, cumulative frequency].
   std::map<const T, double, Histogram_comparator,
-           Memroot_allocator<std::pair<T, double> > > m_buckets;
+           Memroot_allocator<std::pair<const T, double> > > m_buckets;
 public:
   /**
     Singleton constructor.
@@ -162,7 +162,7 @@ private:
 
     @return     true on error, false otherwise
   */
-  static bool create_json_bucket(const std::pair<T, double> &bucket,
+  static bool create_json_bucket(const std::pair<const T, double> &bucket,
                                  Json_array *json_bucket);
 };
 
