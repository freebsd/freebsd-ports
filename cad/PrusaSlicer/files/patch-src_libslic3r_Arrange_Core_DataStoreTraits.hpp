--- src/libslic3r/Arrange/Core/DataStoreTraits.hpp.orig	2024-11-03 17:50:46 UTC
+++ src/libslic3r/Arrange/Core/DataStoreTraits.hpp
@@ -71,7 +71,7 @@ void set_data(ArrItem &itm, const std::string &key, T 
 template<class T, class ArrItem>
 void set_data(ArrItem &itm, const std::string &key, T &&data)
 {
-    WritableDataStoreTraits<ArrItem>::template set(itm, key, std::forward<T>(data));
+    WritableDataStoreTraits<ArrItem>::template set<T>(itm, key, std::forward<T>(data));
 }
 
 template<class T> constexpr bool IsReadWritableDataStore = IsDataStore<T> && IsWritableDataStore<T>;
