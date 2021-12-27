--- plugins/libimhex/include/hex/helpers/utils.hpp.orig	2021-12-26 14:58:20 UTC
+++ plugins/libimhex/include/hex/helpers/utils.hpp
@@ -79,6 +79,12 @@ namespace hex {
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
@@ -91,7 +97,7 @@ namespace hex {
 
         SizeType<Size> swapped;
 
-        if constexpr (!std::has_single_bit(Size) || Size > 16)
+        if constexpr (!has_single_bit(Size) || Size > 16)
                 static_assert(always_false<T>::value, "Invalid type provided!");
 
         switch (Size) {
