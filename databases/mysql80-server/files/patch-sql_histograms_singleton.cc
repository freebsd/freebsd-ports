--- sql/histograms/singleton.cc.orig	2017-01-05 16:22:30 UTC
+++ sql/histograms/singleton.cc
@@ -126,7 +126,7 @@ bool Singleton<T>::histogram_to_json(Jso
 
 
 template <class T>
-bool Singleton<T>::create_json_bucket(const std::pair<T, double> &bucket,
+bool Singleton<T>::create_json_bucket(const std::pair<const T, double> &bucket,
                                       Json_array *json_bucket)
 {
   // Value
