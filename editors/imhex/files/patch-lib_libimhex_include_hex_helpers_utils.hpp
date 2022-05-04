--- lib/libimhex/include/hex/helpers/utils.hpp.orig	2022-04-17 23:53:01 UTC
+++ lib/libimhex/include/hex/helpers/utils.hpp
@@ -94,6 +94,12 @@ namespace hex {
     template<size_t Size>
     using SizeType = typename SizeTypeImpl<Size>::Type;
 
+    // Workaround for FreeBSD versions that std::has_single_bit() is not available
+    template <class T>
+    constexpr bool has_single_bit(T x) {
+        return x != 0 && (((x & (x - 1)) == 0));
+    }
+
     template<typename T>
     constexpr T changeEndianess(const T &value, std::endian endian) {
         if (endian == std::endian::native)
@@ -106,7 +112,7 @@ namespace hex {
 
         SizeType<Size> swapped;
 
-        if constexpr (!std::has_single_bit(Size) || Size > 16)
+        if constexpr (!has_single_bit(Size) || Size > 16)
             static_assert(always_false<T>::value, "Invalid type provided!");
 
         switch (Size) {
