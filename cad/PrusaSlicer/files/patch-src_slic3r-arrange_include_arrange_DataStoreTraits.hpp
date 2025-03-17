--- src/slic3r-arrange/include/arrange/DataStoreTraits.hpp.orig 2025-03-14 14:06:59 UTC
+++ src/slic3r-arrange/include/arrange/DataStoreTraits.hpp
@@ -71,7 +71,7 @@ void set_data(ArrItem &itm, const std::string &key, T 
 template<class T, class ArrItem>
 void set_data(ArrItem &itm, const std::string &key, T &&data)
 {
-    WritableDataStoreTraits<ArrItem>::template set(itm, key, std::forward<T>(data));
+    WritableDataStoreTraits<ArrItem>::template set<>(itm, key, std::forward<T>(data));
 }

