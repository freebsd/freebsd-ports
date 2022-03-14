--- src/util/container_random_util.h.orig	2022-03-13 19:52:08 UTC
+++ src/util/container_random_util.h
@@ -31,13 +31,13 @@
 namespace wyrmgus::container {
 
 template <typename T>
-inline const T::value_type &get_random(const T &container)
+inline const typename T::value_type &get_random(const T &container)
 {
 	return container[random::get()->generate(container.size())];
 }
 
 template <typename T>
-inline const T::value_type &get_random_async(const T &container)
+inline const typename T::value_type &get_random_async(const T &container)
 {
 	return container[random::get()->generate_async(container.size())];
 }
